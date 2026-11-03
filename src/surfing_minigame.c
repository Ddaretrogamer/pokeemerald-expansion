#include "global.h"
#include "bg.h"
#include "dma3.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "surfing_minigame.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"

#define SURFER_X (DISPLAY_WIDTH / 2)
#define COURSE_LENGTH (24 * 0x10000)
#define INITIAL_HP 6000
#define MAX_SCORE 9999
#define INITIAL_SPEED 64
#define MAX_SPEED 512
#define SURF_TAG 0x5750
#define SPRAY_TAG 0x5751
#define SPLASH_TAG 0x5752
#define INTRO_TAG 0x5753
#define INTRO_TILE_BASE 128
#define RESULTS_BORDER_TILE 440
#define WORLD_COLUMNS 64
#define FLAT_HEIGHT (116 - 8)
#define SKY_TILE 0
#define WATER_TILE 11
#define RISING_TILE 6
#define FALLING_TILE 7
#define CREST_TILE 20

enum { SCREEN_INTRO, SCREEN_START, SCREEN_PLAY, SCREEN_PAUSE, SCREEN_COAST, SCREEN_BEACH, SCREEN_GAMEOVER, SCREEN_RESULTS, SCREEN_EXIT };
enum { RIDING, JUMPING, LANDING, CRASHED };
enum { WIN_HUD, WIN_OVERLAY };

struct SurfingGame
{
    u16 worldTilemap[2048];
    u16 uiTilemap[1024];
    u8 heights[WORLD_COLUMNS];
    u8 terrain[WORLD_COLUMNS];
    u32 distance;
    u32 scroll;
    s32 surferY; 
    u16 speed;
    u16 hp;
    u16 radness;
    u16 score;
    u16 frames;
    u16 jumpMagnitude;
    u16 tileStart;
    u16 splashTileStart;
    u16 introTileStart;
    u16 animationFrame;
    u16 sceneFrame;
    u16 tallyHp;
    u16 tallyRadness;
    u16 tallyTotal;
    u8 screen;
    u8 riderState;
    u8 sequence;
    u8 pose; 
    u8 flips;
    u8 flipFlags;
    u8 leftFrames;
    u8 rightFrames;
    u8 stateTimer;
    u8 surferSprite;
    u8 cloudSprites[2];
    u8 bannerSprite;
    u8 bonusSprite;
    u8 spraySprite;
    u8 bonusAge;
    u8 bonusKind;
    u8 normalPalette;
    u8 sprayPalette;
    u8 tallyPhase;
    u8 tallyDelay;
    bool8 descending;
    bool8 completed;
    bool8 newRecord;
    bool8 overlayBorderVisible;
};

static EWRAM_DATA struct SurfingGame *sSurf = NULL;

static const u32 sBackgroundTiles[] = INCBIN_U32("graphics/surfing_minigame/surfing_pikachu_1a.4bpp");
static const u16 sBackgroundPalette[] = INCBIN_U16("graphics/surfing_minigame/surfing_pikachu_1a.gbapal");
static const u32 sSpriteTiles[] = INCBIN_U32("graphics/surfing_minigame/surfing_pikachu_1b.4bpp");
static const u16 sSpritePalette[] = INCBIN_U16("graphics/surfing_minigame/surfing_pikachu_1b.gbapal");
static const u32 sIntroTiles[] = INCBIN_U32("graphics/surfing_minigame/surfing_pikachu_1c.4bpp");
static const u16 sIntroPalette[] = INCBIN_U16("graphics/surfing_minigame/surfing_pikachu_1c.gbapal");
static const u8 sBeachIntro[] = INCBIN_U8("graphics/surfing_minigame/beach_intro.bin");
static const u8 sBeachOutro[] = INCBIN_U8("graphics/surfing_minigame/beach_outro.bin");
static const u8 sTitle[] = INCBIN_U8("graphics/surfing_minigame/title.bin");
static const u8 sUseControlPad[] = INCBIN_U8("graphics/surfing_minigame/use_control_pad.bin");
static const u8 sToSurfRad[] = INCBIN_U8("graphics/surfing_minigame/to_surf_rad.bin");

#include "data/surfing_minigame.h"

static const struct BgTemplate sBgs[] =
{
    { .bg = 0, .charBaseIndex = 0, .mapBaseIndex = 31, .priority = 0 },
    { .bg = 1, .charBaseIndex = 1, .mapBaseIndex = 28, .screenSize = 1, .priority = 2 },
};

static const struct WindowTemplate sWindows[] =
{
    { .bg = 0, .tilemapLeft = 0, .tilemapTop = 17, .width = 30, .height = 3, .paletteNum = 1, .baseBlock = 1 },
    { .bg = 0, .tilemapLeft = 1, .tilemapTop = 3, .width = 28, .height = 12, .paletteNum = 15, .baseBlock = 91 },
    DUMMY_WIN_TEMPLATE,
};


static const struct Subsprite sSurferParts[] =
{
    { .x = -12, .y = -12, .tileOffset = 0 },
    { .x = -4,  .y = -12, .tileOffset = 1 },
    { .x = 4,   .y = -12, .tileOffset = 2 },
    { .x = -12, .y = -4,  .tileOffset = 16 },
    { .x = -4,  .y = -4,  .tileOffset = 17 },
    { .x = 4,   .y = -4,  .tileOffset = 18 },
    { .x = -12, .y = 4,   .tileOffset = 32 },
    { .x = -4,  .y = 4,   .tileOffset = 33 },
    { .x = 4,   .y = 4,   .tileOffset = 34 },
};
static const struct SubspriteTable sSurferPartsTable[] = { { ARRAY_COUNT(sSurferParts), sSurferParts } };
#define PART(x_, y_, tile_) { .x = (x_), .y = (y_), .tileOffset = (tile_) }
static const struct Subsprite sBoardParts[] = { PART(-12, 4, 0), PART(-4, 4, 1), PART(4, 4, 2) };
static const struct SubspriteTable sBoardPartsTable[] = { { ARRAY_COUNT(sBoardParts), sBoardParts } };
static const struct Subsprite sSplashParts[] =
{
    PART(-16, -12, 0), PART(-8, -12, 1), PART(0, -12, 2), PART(8, -12, 3),
    PART(-16, -4, 4), PART(-8, -4, 5), PART(0, -4, 6), PART(8, -4, 7),
    PART(-16, 4, 8), PART(-8, 4, 9), PART(0, 4, 10), PART(8, 4, 11),
};
static const struct SubspriteTable sSplashPartsTable[] = { { ARRAY_COUNT(sSplashParts), sSplashParts } };
static const struct Subsprite sIntroParts[] =
{
    PART(-16, -12, 0), PART(-8, -12, 1), PART(0, -12, 2), PART(8, -12, 3),
    PART(-16, -4, 16), PART(-8, -4, 17), PART(0, -4, 18), PART(8, -4, 19),
    PART(-16, 4, 32), PART(-8, 4, 33), PART(0, 4, 34), PART(8, 4, 35),
};
static const struct SubspriteTable sIntroPartsTable[] = { { ARRAY_COUNT(sIntroParts), sIntroParts } };
static const struct Subsprite sBannerParts[] =
{
    PART(-24, -8, 0), PART(-16, -8, 1), PART(-8, -8, 2), PART(0, -8, 3), PART(8, -8, 4), PART(16, -8, 5),
    PART(-24, 0, 16), PART(-16, 0, 17), PART(-8, 0, 18), PART(0, 0, 19), PART(8, 0, 20), PART(16, 0, 21),
};
static const struct SubspriteTable sBannerPartsTable[] = { { ARRAY_COUNT(sBannerParts), sBannerParts } };
static const struct Subsprite sSprayParts[] = { PART(11, -4, 0), PART(3, 4, 15), PART(11, 4, 16) };
static const struct SubspriteTable sSprayPartsTable[] = { { ARRAY_COUNT(sSprayParts), sSprayParts } };
static const struct Subsprite sBonusParts[][4] =
{
    { PART(-12, -4, 0xBF), PART(-4, -4, 0xD5), PART(4, -4, 0xD0) },
    { PART(-16, -4, 0xBF), PART(-8, -4, 0xD1), PART(0, -4, 0xD5), PART(8, -4, 0xD0) },
    { PART(-16, -4, 0xBF), PART(-8, -4, 0xD3), PART(0, -4, 0xD5), PART(8, -4, 0xD0) },
    { PART(-16, -4, 0xBF), PART(-8, -4, 0xD1), PART(0, -4, 0xD8), PART(8, -4, 0xD0) },
    { PART(-16, -4, 0xBF), PART(-8, -4, 0xD5), PART(0, -4, 0xD0), PART(8, -4, 0xD0) },
};
static const struct SubspriteTable sBonusPartsTable[] =
{
    { 3, sBonusParts[0] }, { 4, sBonusParts[1] }, { 4, sBonusParts[2] }, { 4, sBonusParts[3] }, { 4, sBonusParts[4] },
};
#undef PART
static const struct Subsprite sCloudParts[] =
{
    { .x = -20, .y = -4, .tileOffset = 0 },
    { .x = -12, .y = -4, .tileOffset = 1 },
    { .x = -4,  .y = -4, .tileOffset = 1 },
    { .x = 4,   .y = -4, .tileOffset = 2 },
    { .x = 12,  .y = -4, .tileOffset = 3 },
};
static const struct SubspriteTable sCloudPartsTable[] = { { ARRAY_COUNT(sCloudParts), sCloudParts } };
static const struct SpriteTemplate sSpriteTemplate =
{
    .tileTag = SURF_TAG,
    .paletteTag = SURF_TAG,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u8 sPoseTiles[7][2] =
{
    { 0x00, 0x36 }, { 0x03, 0x39 }, { 0x06, 0x3C }, { 0x09, 0x60 },
    { 0x0C, 0x63 }, { 0x30, 0x66 }, { 0x33, 0x69 },
};
static const u8 sSequenceStarts[] = { 0x01, 0x0E, 0x1A, 0x29, 0x32, 0x40, 0x4D, 0x5C };
static const u16 sSameFlipScores[] = { 0, 50, 150, 350 };

static const u8 sTextPaused[] = _("PAUSED\n\n{A_BUTTON} / {START_BUTTON} RESUME\n{B_BUTTON} QUIT");
static const u8 sTextGameOver[] = _("OUT OF HP");
static const u8 sTextNewRecord[] = _("NEW PERSONAL BEST!");
static const u8 sTextReturn[] = _("{A_BUTTON} PLAY AGAIN    {B_BUTTON} RETURN");
static const u8 sTextBest[] = _("BEST");
static const u8 sTextHpLeft[] = _("HP LEFT");
static const u8 sTextRadnessScore[] = _("RADNESS");
static const u8 sTextTotal[] = _("TOTAL");
static const u8 sTextPoints[] = _(" PTS");
static const u8 sTextCount[] = _("{A_BUTTON} SKIP COUNT");

static const s8 sRipple[] =
{
    0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 0, 0,
    0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, 0, 0,
};

static void CB2_InitSurfing(void);
static void CB2_Surfing(void);
static void HideOverlay(void);
static void DrawOverlayBorder(void);
static void ShowResults(void);
static void LoadResultsBorder(void);
static void StartRun(void);

static u16 GetBestScore(void)
{
    return gSaveBlock2Ptr->surfingBestScore;
}

void ResetSurfingMinigameRecord(void)
{
    gSaveBlock2Ptr->surfingBestScore = 0;
}

static void VBlankCB_Surfing(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    if (sSurf->screen == SCREEN_PLAY)
    {
        gScanlineEffect.state = 1;
        ScanlineEffect_InitHBlankDmaTransfer();
    }
    else
    {
        if (gScanlineEffect.state)
            ScanlineEffect_Stop();
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
}

static void UpdateRippleBuffer(u8 buffer)
{
    for (u32 y = 0; y < DISPLAY_HEIGHT; y++)
    {
        u32 phase = y + (y >= 16 ? sSurf->animationFrame / 2 : 0);
        s16 offset = sSurf->screen == SCREEN_PLAY ? sRipple[phase % ARRAY_COUNT(sRipple)] : 0;
        gScanlineEffectRegBuffers[buffer][y] = offset & 0x1FF;
    }
    gScanlineEffectRegBuffers[buffer][DISPLAY_HEIGHT] = 0;
}

static void InitRipple(void)
{
    const struct ScanlineEffectParams params =
    {
        .dmaDest = (void *)REG_ADDR_BG1VOFS,
        .dmaControl = SCANLINE_EFFECT_DMACNT_16BIT,
        .initState = 0, // VBlank enables ripple effect when the game is playing, not on intro or menus.
    };
    UpdateRippleBuffer(0);
    UpdateRippleBuffer(1);
    ScanlineEffect_SetParams(params);
}

static void Task_EnterSurfing(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
    }
    else if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2(CB2_InitSurfing);
    }
}

void StartSurfingMinigame(void)
{
    gSpecialVar_Result = 0;
    gSpecialVar_0x8005 = FALSE;
    gSpecialVar_0x8006 = GetBestScore();
    CreateTask(Task_EnterSurfing, 0);
}

static void Print(u8 window, u8 x, u8 y, const u8 *text)
{
    AddTextPrinterParameterized(window, FONT_SMALL, text, x, y, TEXT_SKIP_DRAW, NULL);
}

static void DrawHud(void)
{
    u32 digit = 1000;
    u32 markerX = 14 * 8 - min(sSurf->distance, COURSE_LENGTH) * (11 * 8) / COURSE_LENGTH;
    u32 *pixels = (u32 *)GetWindowAttribute(WIN_HUD, WINDOW_TILE_DATA);

    FillWindowPixelBuffer(WIN_HUD, PIXEL_FILL(3));
    CopyToWindowPixelBuffer(WIN_HUD, sBackgroundTiles + 0x15 * 8, 2 * TILE_SIZE_4BPP, 1);
    CopyToWindowPixelBuffer(WIN_HUD, sBackgroundTiles + 0x17 * 8, 2 * TILE_SIZE_4BPP, 31);
    for (u32 x = 3; x <= 14; x++)
        CopyToWindowPixelBuffer(WIN_HUD, sBackgroundTiles + 0x19 * 8, TILE_SIZE_4BPP, 30 + x);

    for (u32 y = 0; y < 8; y++)
    {
        u32 source = sSpriteTiles[0xFE * 8 + y];
        for (u32 x = 0; x < 8; x++)
        {
            u32 color = (source >> (x * 4)) & 15;
            u32 destX = markerX + x;
            u32 shift = (destX % 8) * 4;
            u32 *dest = &pixels[(30 + destX / 8) * 8 + y];
            if (color != 3)
                *dest = (*dest & ~(15u << shift)) | (color << shift);
        }
    }
    CopyToWindowPixelBuffer(WIN_HUD, sBackgroundTiles + 0x1B * 8, 2 * TILE_SIZE_4BPP, 48);
    for (u32 x = 22; x < 26; x++, digit /= 10)
        CopyToWindowPixelBuffer(WIN_HUD, sSpriteTiles + (0xD0 + sSurf->hp / digit % 10) * 8, TILE_SIZE_4BPP, 30 + x);

    for (u32 i = 0; i < 90 * TILE_SIZE_4BPP / sizeof(u32); i++)
    {
        u32 word = pixels[i];
        for (u32 shift = 0; shift < 32; shift += 4)
            if (((word >> shift) & 15) == 0)
                word |= 4u << shift;
        pixels[i] = word;
    }
    CopyWindowToVram(WIN_HUD, COPYWIN_GFX);
}

static void ShowOverlay(const u8 *text)
{
    u32 width = min(28, (GetStringWidth(FONT_SMALL, text, 0) + 16 + 7) / 8);
    u32 height = (4 * GetFontAttribute(FONT_SMALL, FONTATTR_MAX_LETTER_HEIGHT) + 8 + 7) / 8;

    HideOverlay();
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_LEFT, (30 - width) / 2);
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_TOP, (17 - height) / 2);
    gWindows[WIN_OVERLAY].window.width = width;
    gWindows[WIN_OVERLAY].window.height = height;
    FillWindowPixelBuffer(WIN_OVERLAY, PIXEL_FILL(1));
    Print(WIN_OVERLAY, 8, 4, text);
    PutWindowTilemap(WIN_OVERLAY);
    DrawOverlayBorder();
    CopyWindowToVram(WIN_OVERLAY, COPYWIN_FULL);
}

static void HideOverlay(void)
{
    if (sSurf->overlayBorderVisible)
    {
        u32 left = GetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_LEFT) - 1;
        u32 top = GetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_TOP) - 1;
        u32 right = left + GetWindowAttribute(WIN_OVERLAY, WINDOW_WIDTH) + 1;
        u32 bottom = top + GetWindowAttribute(WIN_OVERLAY, WINDOW_HEIGHT) + 1;
        for (u32 y = top; y <= bottom; y++)
            for (u32 x = left; x <= right; x++)
                sSurf->uiTilemap[y * 32 + x] = 0;
        sSurf->overlayBorderVisible = FALSE;
    }
    ClearWindowTilemap(WIN_OVERLAY);
    CopyWindowToVram(WIN_OVERLAY, COPYWIN_MAP);
}

static u16 TilemapIndex(u8 x, u8 y)
{
    return (x / 32) * 1024 + y * 32 + (x % 32);
}

static u16 IntroTile(u8 tile)
{
    // Yellow loaded these tiles at $8800 and addressed them as signed bytes.
    return (2 << 12) | (INTRO_TILE_BASE + ((tile + 128) & 255));
}

static void DrawBeach(bool32 intro)
{
    const u8 *map = intro ? sBeachIntro : sBeachOutro;
    u32 rows = intro ? sizeof(sBeachIntro) / 20 : sizeof(sBeachOutro) / 20;

    for (u32 y = 0; y < 32; y++)
    {
        for (u32 x = 0; x < WORLD_COLUMNS; x++)
        {
            u8 tile = 0xFF;
            if (y >= 7)
            {
                u32 mapX = x < 5 ? 0 : min(19, x - 5);
                u32 mapY = y - 7;
                if (mapY >= rows)
                    mapY = rows - 2 + (mapY - rows) % 2;
                tile = map[mapY * 20 + mapX];
            }
            sSurf->worldTilemap[TilemapIndex(x, y)] = intro ? IntroTile(tile) : tile == 0xFF ? SKY_TILE : tile;
        }
    }
    if (intro)
    {
        for (u32 y = 0; y < 6; y++)
            for (u32 x = 0; x < 12; x++)
                sSurf->worldTilemap[TilemapIndex(9 + x, 1 + y)] = (IntroTile(sTitle[y * 12 + x]) & 0xFFF) | (3 << 12);
        for (u32 y = 8; y < 11; y++)
            for (u32 x = 8; x < 23; x++)
                sSurf->worldTilemap[TilemapIndex(x, y)] = IntroTile(0xFF);
        for (u32 x = 0; x < sizeof(sUseControlPad); x++)
            sSurf->worldTilemap[TilemapIndex(8 + x, 8)] = IntroTile(sUseControlPad[x]);
        for (u32 x = 0; x < sizeof(sToSurfRad); x++)
            sSurf->worldTilemap[TilemapIndex(9 + x, 10)] = IntroTile(sToSurfRad[x]);
    }
    CopyBgTilemapBufferToVram(1);
}

static void DrawWaveSlice(u8 column, u8 pattern)
{
    u32 row, half;
    for (half = 0; half < 2; half++)
    {
        u8 x = (column + half) % WORLD_COLUMNS;
        sSurf->heights[x] = sWaveHeights[pattern][half] - 8;
        sSurf->terrain[x] = WATER_TILE;
        for (row = 0; row < 8; row++)
        {
            const u8 *metatile = sWaveMetatiles[sWavePatterns[pattern][row]];
            u8 top = metatile[half];
            u8 bottom = metatile[half + 2];
            sSurf->worldTilemap[TilemapIndex(x, row * 2 + 1)] = top;
            sSurf->worldTilemap[TilemapIndex(x, row * 2 + 2)] = bottom;
            if (top == CREST_TILE || bottom == CREST_TILE)
                sSurf->terrain[x] = CREST_TILE;
            else if (sSurf->terrain[x] != CREST_TILE)
            {
                if (top == RISING_TILE || bottom == RISING_TILE)
                    sSurf->terrain[x] = RISING_TILE;
                else if (top == FALLING_TILE || bottom == FALLING_TILE)
                    sSurf->terrain[x] = FALLING_TILE;
            }
        }
    }
}

static u8 NextWavePattern(void)
{
    u8 pattern = sWaveSequence[sSurf->sequence];
    switch (pattern)
    {
    case 0xFE:
        if ((sSurf->distance >> 16) == 22)
            sSurf->sequence = 0x6A; // Yellow's final wave
        else if ((sSurf->distance >> 16) < 22)
            sSurf->sequence = sSequenceStarts[Random() % ARRAY_COUNT(sSequenceStarts)];
        return 0;
    case 0xFF:
        sSurf->sequence = 0;
        return 0;
    case 0xFD:
        return 0;
    default:
        sSurf->sequence++;
        return pattern;
    }
}

static void ResetRun(void)
{
    u32 i;
    sSurf->distance = 0;
    sSurf->scroll = 0;
    sSurf->speed = INITIAL_SPEED;
    sSurf->hp = INITIAL_HP;
    sSurf->radness = 0;
    sSurf->score = 0;
    sSurf->frames = 0;
    sSurf->pose = 4;
    sSurf->riderState = RIDING;
    sSurf->stateTimer = 0;
    sSurf->sequence = 0;
    sSurf->jumpMagnitude = 0;
    sSurf->descending = FALSE;
    sSurf->flips = 0;
    sSurf->flipFlags = 0;
    sSurf->leftFrames = 0;
    sSurf->rightFrames = 0;
    sSurf->surferY = FLAT_HEIGHT * 256;
    sSurf->completed = FALSE;
    sSurf->newRecord = FALSE;
    sSurf->sceneFrame = 0;
    sSurf->animationFrame = 0;
    sSurf->bonusAge = 0;
    gSprites[sSurf->spraySprite].invisible = TRUE;
    HideOverlay();
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_LEFT, 1);
    gWindows[WIN_OVERLAY].window.width = 28;
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_TOP, 3);
    gWindows[WIN_OVERLAY].window.height = 12;
    SetWindowAttribute(WIN_HUD, WINDOW_PALETTE_NUM, 1);
    PutWindowTilemap(WIN_HUD);
    CpuFill16(0, sSurf->worldTilemap, sizeof(sSurf->worldTilemap));
    for (i = 0; i < WORLD_COLUMNS; i += 2)
        DrawWaveSlice(i, 0);
    CopyBgTilemapBufferToVram(1);
    ChangeBgX(1, 0, BG_COORD_SET);
    DrawHud();
}

static void StartRun(void)
{
    ResetRun();
    sSurf->screen = SCREEN_START;
}

static void SetSpriteVisual(struct Sprite *sprite, const struct SubspriteTable *parts, u16 tile, u8 palette, u8 flip)
{
    SetSubspriteTables(sprite, parts);
    sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    sprite->oam.tileNum = tile;
    sprite->oam.paletteNum = palette;
    sprite->oam.matrixNum = flip;
}

static void UpdateSprites(void)
{
    struct Sprite *surfer = &gSprites[sSurf->surferSprite];
    struct Sprite *banner = &gSprites[sSurf->bannerSprite];
    struct Sprite *bonus = &gSprites[sSurf->bonusSprite];
    u8 pose = sSurf->pose - 1;

    // Keep the last rendered scene intact throughout the return fade.
    if (sSurf->screen == SCREEN_EXIT)
        return;
    // Objects win ties with backgrounds, so priority zero clears the panel.
    surfer->oam.priority = sSurf->screen == SCREEN_RESULTS ? 0 : 1;
    surfer->x = SURFER_X;
    surfer->y = sSurf->surferY >> 8;
    SetSpriteVisual(surfer, sSurferPartsTable, sSurf->tileStart + sPoseTiles[pose % 7][(sSurf->animationFrame >> 3) & 1],
                    sSurf->normalPalette, pose >= 7 ? ST_OAM_HFLIP | ST_OAM_VFLIP : 0);
    if (sSurf->riderState == CRASHED)
    {
        if (sSurf->stateTimer > 64)
            SetSpriteVisual(surfer, sSplashPartsTable, sSurf->splashTileStart + ((sSurf->animationFrame >> 1) & 1) * 12,
                            sSurf->sprayPalette, 0);
        else
            SetSpriteVisual(surfer, sBoardPartsTable, sSurf->tileStart + 0x98, sSurf->normalPalette, 0);
    }
    if (sSurf->screen == SCREEN_INTRO)
    {
        surfer->x = SURFER_X + sSurf->sceneFrame / 2;
        surfer->y = FLAT_HEIGHT;
        SetSpriteVisual(surfer, sIntroPartsTable, sSurf->introTileStart + ((sSurf->animationFrame / 7) & 3) * 4,
                        sSurf->normalPalette, ST_OAM_HFLIP);
    }
    else if (sSurf->screen == SCREEN_BEACH || sSurf->screen == SCREEN_RESULTS)
    {
        surfer->x = SURFER_X - (sSurf->screen == SCREEN_RESULTS ? 16 : min(16, sSurf->sceneFrame / 4));
        surfer->y = FLAT_HEIGHT;
        if (sSurf->screen == SCREEN_RESULTS || sSurf->sceneFrame >= 48)
        {
            bool32 celebrate = sSurf->screen == SCREEN_RESULTS && sSurf->tallyPhase == 8;
            u16 tile = 0xA0;
            if (celebrate)
            {
                surfer->y -= (sSurf->animationFrame & 31) > 15 ? 8 : 0;
                tile = (sSurf->animationFrame & 8) ? 0xA0 : 0xA3;
            }
            SetSpriteVisual(surfer, sSurferPartsTable, sSurf->tileStart + tile,
                            sSurf->normalPalette, 0);
        }
    }
    for (u32 i = 0; i < ARRAY_COUNT(sSurf->cloudSprites); i++)
    {
        struct Sprite *cloud = &gSprites[sSurf->cloudSprites[i]];
        cloud->invisible = sSurf->screen == SCREEN_INTRO || sSurf->screen == SCREEN_BEACH || sSurf->screen == SCREEN_RESULTS;
        cloud->x = ((48 + i * 144 + (sSurf->scroll >> 10)) & 255) - 8;
        cloud->oam.tileNum = sSurf->tileStart + 0xEC;
    }
    banner->invisible = TRUE;
    if (sSurf->screen == SCREEN_START || sSurf->screen == SCREEN_GAMEOVER || (sSurf->screen == SCREEN_COAST && sSurf->sceneFrame < 64))
    {
        banner->invisible = FALSE;
        banner->x = sSurf->screen == SCREEN_START ? max(SURFER_X, DISPLAY_WIDTH + 24 - sSurf->sceneFrame * 4) : SURFER_X;
        banner->y = 64;
        banner->oam.tileNum = sSurf->tileStart + (sSurf->screen == SCREEN_START ? 0xE0 : sSurf->screen == SCREEN_GAMEOVER ? 0xCA : 0xE6);
    }
    bonus->invisible = sSurf->bonusAge == 0;
    if (sSurf->bonusAge)
    {
        bonus->subspriteTableNum = sSurf->bonusKind;
        bonus->y2 = -(24 - sSurf->bonusAge) / 4;
    }

}

static void CopyObjectTile(u32 *dest, const u32 *source, bool32 flip)
{
    for (u32 y = 0; y < 8; y++)
    {
        u32 row = 0;
        for (u32 x = 0; x < 8; x++)
        {
            u32 color = (source[y] >> ((flip ? 7 - x : x) * 4)) & 15;
            if (color == 0 || color == 3)
                color ^= 3;
            row |= color << (x * 4);
        }
        dest[y] = row;
    }
}

static void CopySplashTile(u32 *dest, u8 tile, bool32 flip)
{
    CopyObjectTile(dest, sSpriteTiles + tile * 8, flip);
}

static void LoadIntroGraphics(void)
{
    // The intro's object tiles share Yellow's $8800 bank with its title BG.
    // They are the first 48 tiles of sheet 1c, not sheet 1b's tile $80.
    u32 tiles[48][8];
    const struct SpriteSheet sheet = { tiles, sizeof(tiles), INTRO_TAG };
    for (u32 i = 0; i < ARRAY_COUNT(tiles); i++)
        CopyObjectTile(tiles[i], sIntroTiles + i * 8, FALSE);
    LoadSpriteSheet(&sheet);
    sSurf->introTileStart = GetSpriteTileStartByTag(INTRO_TAG);
}

static void LoadSplashGraphics(void)
{
    u32 tiles[2][12][8] = {0};
    const struct SpriteSheet sheet = { tiles, sizeof(tiles), SPLASH_TAG };
    CopySplashTile(tiles[0][4], 0xA7, TRUE);
    CopySplashTile(tiles[0][7], 0xA7, FALSE);
    CopySplashTile(tiles[0][8], 0xB7, TRUE);
    CopySplashTile(tiles[0][9], 0xB6, TRUE);
    CopySplashTile(tiles[0][10], 0xB6, FALSE);
    CopySplashTile(tiles[0][11], 0xB7, FALSE);
    for (u32 row = 0; row < 3; row++)
    {
        CopySplashTile(tiles[1][row * 4], 0xA8 + row * 16, FALSE);
        CopySplashTile(tiles[1][row * 4 + 1], 0xA9 + row * 16, FALSE);
        CopySplashTile(tiles[1][row * 4 + 2], 0xA9 + row * 16, TRUE);
        CopySplashTile(tiles[1][row * 4 + 3], 0xA8 + row * 16, TRUE);
    }
    LoadSpriteSheet(&sheet);
    sSurf->splashTileStart = GetSpriteTileStartByTag(SPLASH_TAG);
}

static u8 CreateEffectSprite(const struct SubspriteTable *parts, u16 tile, u8 palette)
{
    u8 id = CreateSprite(&sSpriteTemplate, 0, 0, 0);
    SetSpriteVisual(&gSprites[id], parts, tile, palette, 0);
    gSprites[id].animPaused = TRUE;
    gSprites[id].oam.priority = 1;
    gSprites[id].invisible = TRUE;
    return id;
}

static void CreateGameSprites(void)
{
    static const u8 colorMap[16] = { 3, 1, 2, 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    u16 colors[16];
    const struct SpriteSheet sheet = { sSpriteTiles, sizeof(sSpriteTiles), SURF_TAG };
    const struct SpritePalette palette = { colors, SURF_TAG };
    u16 *tiles;

    LoadSpriteSheet(&sheet);
    sSurf->tileStart = GetSpriteTileStartByTag(SURF_TAG);
    tiles = (u16 *)((u8 *)OBJ_VRAM0 + sSurf->tileStart * TILE_SIZE_4BPP);
    for (u32 i = 0; i < sizeof(sSpriteTiles) / sizeof(u16); i++)
    {
        u16 source = ((const u16 *)sSpriteTiles)[i];
        u16 result = 0;
        for (u32 shift = 0; shift < 16; shift += 4)
            result |= colorMap[(source >> shift) & 15] << shift;
        tiles[i] = result;
    }
    CpuCopy16(sSpritePalette, colors, sizeof(colors));
    colors[0] = sSpritePalette[3];
    colors[3] = sSpritePalette[0];
    LoadSpritePalette(&palette);
    sSurf->normalPalette = IndexOfSpritePaletteTag(SURF_TAG);
    colors[2] = RGB_WHITE; // Yellow's second OBJ palette maps the spray to foam.
    LoadSpritePaletteWithTag(colors, SPRAY_TAG);
    sSurf->sprayPalette = IndexOfSpritePaletteTag(SPRAY_TAG);
    LoadSplashGraphics();
    LoadIntroGraphics();
    sSurf->surferSprite = CreateSprite(&sSpriteTemplate, SURFER_X, FLAT_HEIGHT, 0);
    SetSubspriteTables(&gSprites[sSurf->surferSprite], sSurferPartsTable);
    gSprites[sSurf->surferSprite].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    gSprites[sSurf->surferSprite].oam.priority = 1;
    gSprites[sSurf->surferSprite].animPaused = TRUE;
    for (u32 i = 0; i < ARRAY_COUNT(sSurf->cloudSprites); i++)
    {
        u8 id = CreateSprite(&sSpriteTemplate, 48 + i * 144, 36 + i * 8, 1);
        sSurf->cloudSprites[i] = id;
        SetSubspriteTables(&gSprites[id], sCloudPartsTable);
        gSprites[id].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[id].oam.priority = 1;
        gSprites[id].animPaused = TRUE;
    }
    sSurf->bannerSprite = CreateEffectSprite(sBannerPartsTable, sSurf->tileStart + 0xE0, sSurf->normalPalette);
    sSurf->bonusSprite = CreateEffectSprite(sBonusPartsTable, sSurf->tileStart, sSurf->normalPalette);
    sSurf->spraySprite = CreateEffectSprite(sSprayPartsTable, sSurf->tileStart + 0xA7, sSurf->sprayPalette);
}

static void CB2_InitSurfing(void)
{
    u16 titlePalette[16];
    // Allocate after the field has faded and the implicit script wait has run.
    sSurf = AllocZeroedUnchecked(sizeof(*sSurf));
    if (sSurf == NULL)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
    }
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
    ScanlineEffect_Stop();
    ScanlineEffect_Clear();
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    FreeAllWindowBuffers();
    ResetPaletteFade();
    ResetTempTileDataBuffers();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgs, ARRAY_COUNT(sBgs));
    SetBgTilemapBuffer(0, sSurf->uiTilemap);
    SetBgTilemapBuffer(1, sSurf->worldTilemap);
    LoadBgTiles(1, sBackgroundTiles, sizeof(sBackgroundTiles), 0);
    LoadBgTiles(1, sIntroTiles, sizeof(sIntroTiles), INTRO_TILE_BASE);
    LoadPalette(sBackgroundPalette, BG_PLTT_ID(0), sizeof(sBackgroundPalette));
    LoadPalette(sBackgroundPalette, BG_PLTT_ID(1), sizeof(sBackgroundPalette));
    LoadPalette(sIntroPalette, BG_PLTT_ID(2), sizeof(sIntroPalette));
    CpuCopy16(sIntroPalette, titlePalette, sizeof(titlePalette));
    titlePalette[1] = RGB(31, 18, 0);
    titlePalette[2] = RGB(31, 28, 0);
    LoadPalette(titlePalette, BG_PLTT_ID(3), sizeof(titlePalette));
    Menu_LoadStdPalAt(BG_PLTT_ID(15));
    if (!InitWindowsUnchecked(sWindows))
    {
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        Free(sSurf);
        sSurf = NULL;
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
    }
    DeactivateAllTextPrinters();
    // BG0 tile zero must be transparent between the windows.
    CpuFastFill(0, (void *)BG_CHAR_ADDR(0), TILE_SIZE_4BPP);
    LoadResultsBorder();
    PutWindowTilemap(WIN_HUD);
    CreateGameSprites();
    ResetRun();
    sSurf->screen = SCREEN_INTRO;
    ClearWindowTilemap(WIN_HUD);
    DrawBeach(TRUE);
    CopyBgTilemapBufferToVram(0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    // InitBgsFromTemplates resets software coordinates, but leaves the field's
    // hardware scroll registers intact.
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    InitRipple();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetVBlankCallback(VBlankCB_Surfing);
    PlayNewMapMusic(MUS_SURFING_PIKACHU);
    SetMainCallback2(CB2_Surfing);
}

static void BeginExit(void)
{
    gSpecialVar_Result = sSurf->score;
    gSpecialVar_0x8005 = sSurf->completed;
    gSpecialVar_0x8006 = GetBestScore();
    sSurf->screen = SCREEN_EXIT;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

static void LoadResultsBorder(void)
{
    u32 tiles[6 * TILE_SIZE_4BPP / sizeof(u32)];

    // Reuse the intro's six frame tiles, giving black an opaque palette entry.
    for (u32 i = 0; i < ARRAY_COUNT(tiles); i++)
    {
        u32 word = sIntroTiles[128 * 8 + i];
        for (u32 shift = 0; shift < 32; shift += 4)
            if (((word >> shift) & 15) == 0)
                word |= 4u << shift;
        tiles[i] = word;
    }
    // Called during initialization with the backgrounds disabled.
    CpuCopy16(tiles, (void *)(BG_CHAR_ADDR(0) + RESULTS_BORDER_TILE * TILE_SIZE_4BPP), sizeof(tiles));
}

static void DrawOverlayBorder(void)
{
    u16 tile = (1 << 12) | RESULTS_BORDER_TILE;
    u32 left = GetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_LEFT) - 1;
    u32 top = GetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_TOP) - 1;
    u32 right = left + GetWindowAttribute(WIN_OVERLAY, WINDOW_WIDTH) + 1;
    u32 bottom = top + GetWindowAttribute(WIN_OVERLAY, WINDOW_HEIGHT) + 1;

    sSurf->uiTilemap[top * 32 + left] = tile;
    sSurf->uiTilemap[top * 32 + right] = tile + 1;
    sSurf->uiTilemap[bottom * 32 + left] = tile + 2;
    sSurf->uiTilemap[bottom * 32 + right] = tile + 3;
    for (u32 y = top + 1; y < bottom; y++)
    {
        sSurf->uiTilemap[y * 32 + left] = tile + 4;
        sSurf->uiTilemap[y * 32 + right] = tile + 4;
    }
    for (u32 x = left + 1; x < right; x++)
    {
        sSurf->uiTilemap[top * 32 + x] = tile + 5;
        sSurf->uiTilemap[bottom * 32 + x] = tile + 5;
    }
    sSurf->overlayBorderVisible = TRUE;
}

static void PrintResultCentered(u8 y, const u8 *text)
{
    u32 width = GetStringWidth(FONT_SMALL, text, 0);
    Print(WIN_OVERLAY, (160 - width) / 2, y, text);
}

static void PrintResultValue(u8 y, const u8 *label, u16 value)
{
    u8 text[12];
    u32 width;

    StringCopy(ConvertIntToDecimalStringN(text, value, STR_CONV_MODE_LEFT_ALIGN, 4), sTextPoints);
    width = GetStringWidth(FONT_SMALL, text, 0);
    Print(WIN_OVERLAY, 8, y, label);
    Print(WIN_OVERLAY, 152 - width, y, text);
}

static void DrawResults(void)
{
    FillWindowPixelBuffer(WIN_OVERLAY, PIXEL_FILL(1));
    if (sSurf->tallyPhase >= 1)
        PrintResultValue(2, sTextHpLeft, sSurf->tallyHp);
    if (sSurf->tallyPhase >= 2)
        PrintResultValue(14, sTextRadnessScore, sSurf->tallyRadness);
    if (sSurf->tallyPhase >= 3)
        PrintResultValue(26, sTextTotal, sSurf->tallyTotal);
    if (sSurf->tallyPhase >= 7)
    {
        PrintResultValue(42, sTextBest, GetBestScore());
        if (sSurf->newRecord)
            PrintResultCentered(54, sTextNewRecord);
    }
    FillWindowPixelBuffer(WIN_HUD, PIXEL_FILL(1));
    Print(WIN_HUD, 4, 4, sSurf->tallyPhase == 8 ? sTextReturn : sTextCount);
    CopyWindowToVram(WIN_HUD, COPYWIN_GFX);
    PutWindowTilemap(WIN_OVERLAY);
    DrawOverlayBorder();
    CopyWindowToVram(WIN_OVERLAY, COPYWIN_FULL);
}

static void ShowResults(void)
{
    sSurf->score = min(MAX_SCORE, sSurf->hp + sSurf->radness);
    sSurf->newRecord = sSurf->score > GetBestScore();
    if (sSurf->newRecord)
    {
        gSaveBlock2Ptr->surfingBestScore = sSurf->score;
    }
    sSurf->screen = SCREEN_RESULTS;
    sSurf->riderState = RIDING;
    sSurf->tallyHp = sSurf->hp;
    sSurf->tallyRadness = sSurf->radness;
    sSurf->tallyTotal = 0;
    sSurf->tallyPhase = 0;
    sSurf->tallyDelay = 32;
    HideOverlay();
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_LEFT, 5);
    gWindows[WIN_OVERLAY].window.width = 20;
    SetWindowAttribute(WIN_OVERLAY, WINDOW_TILEMAP_TOP, 1);
    gWindows[WIN_OVERLAY].window.height = 9;
    SetWindowAttribute(WIN_HUD, WINDOW_PALETTE_NUM, 15);
    PutWindowTilemap(WIN_HUD);
    DrawResults();
}

static void FinishRun(bool32 completed)
{
    sSurf->completed = completed;
    sSurf->score = 0;
    sSurf->sceneFrame = 0;
    sSurf->screen = completed ? SCREEN_COAST : SCREEN_GAMEOVER;
    if (!completed)
    {
        sSurf->speed = 0;
        PlaySE(SE_RG_POKE_JUMP_FAILURE);
    }
}

static void StartCelebration(void)
{
    sSurf->tallyPhase = 8;
    sSurf->animationFrame = 0;
    PlayCry_NormalNoDucking(SPECIES_PIKACHU, 0, CRY_VOLUME, CRY_PRIORITY_NORMAL);
}

static void UpdateResults(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        sSurf->tallyHp = 0;
        sSurf->tallyRadness = 0;
        sSurf->tallyTotal = sSurf->score;
        StartCelebration();
        DrawResults();
        return;
    }
    if (sSurf->tallyDelay)
    {
        sSurf->tallyDelay--;
        return;
    }
    if (sSurf->tallyPhase == 4 || sSurf->tallyPhase == 6)
    {
        u16 *remaining = sSurf->tallyPhase == 4 ? &sSurf->tallyHp : &sSurf->tallyRadness;
        u16 amount = min(99, *remaining);
        *remaining -= amount;
        sSurf->tallyTotal = min(MAX_SCORE, sSurf->tallyTotal + amount);
        if (*remaining == 0)
        {
            sSurf->tallyPhase++;
            sSurf->tallyDelay = 64;
            if (sSurf->tallyPhase == 7)
                PlaySE(sSurf->newRecord ? SE_SUCCESS : SE_RG_POKE_JUMP_SUCCESS);
        }
    }
    else
    {
        sSurf->tallyPhase++;
        if (sSurf->tallyPhase == 8)
            StartCelebration();
        sSurf->tallyDelay = sSurf->tallyPhase == 1 || sSurf->tallyPhase == 2 ? 64 : sSurf->tallyPhase == 3 ? 32 : 0;
    }
    DrawResults();
}

static s16 SurfaceHeight(u32 worldX, u8 *terrain)
{
    u8 col = (worldX / 8) % WORLD_COLUMNS;
    u8 pixel = worldX % 8;
    s16 height = sSurf->heights[col];
    *terrain = sSurf->terrain[col];
    if (*terrain == RISING_TILE || *terrain == CREST_TILE)
        height -= pixel;
    else if (*terrain == FALLING_TILE)
        height += pixel;
    return height;
}

static void SpawnBonus(u16 bonus)
{
    struct Sprite *sprite = &gSprites[sSurf->bonusSprite];
    sSurf->bonusAge = 24;
    sSurf->bonusKind = bonus == 50 ? 0 : bonus == 150 ? 1 : bonus == 350 ? 2 : bonus == 180 ? 3 : 4;
    sprite->x = SURFER_X;
    sprite->y = max(16, (sSurf->surferY >> 8) - 20);
}

static void UpdateEffects(void)
{
    sSurf->animationFrame++;
    if (sSurf->bonusAge)
        sSurf->bonusAge--;
}

static void RotateBoard(void)
{
    if (sSurf->frames % 2 != 0)
        return;
    if (JOY_HELD(DPAD_LEFT))
    {
        sSurf->rightFrames = 0;
        if (++sSurf->leftFrames >= 12)
        {
            sSurf->leftFrames = 0;
            sSurf->flips = min(3, sSurf->flips + 1);
            sSurf->flipFlags |= 1;
        }
        if (++sSurf->pose > 14)
            sSurf->pose = 1;
    }
    else if (JOY_HELD(DPAD_RIGHT))
    {
        sSurf->leftFrames = 0;
        if (++sSurf->rightFrames >= 14)
        {
            sSurf->rightFrames = 0;
            sSurf->flips = min(3, sSurf->flips + 1);
            sSurf->flipFlags |= 2;
        }
        if (--sSurf->pose == 0)
            sSurf->pose = 14;
    }
}

static void Land(u8 terrain)
{
    // Landing tables retain Yellow's asymmetric front/back flip handling.
    static const u8 flat[] = { 3, 2, 1, 0, 1, 2, 3 };
    static const u8 rising[] = { 3, 3, 3, 2, 1, 0, 1 };
    static const u8 falling[] = { 1, 0, 1, 2, 3, 3, 3 };
    static const u8 crest[] = { 3, 2, 1, 0, 0, 1, 2 };
    const u8 *ratings = flat;
    u8 rating = 3;
    if (terrain == RISING_TILE)
        ratings = rising;
    else if (terrain == FALLING_TILE)
        ratings = falling;
    else if (terrain == CREST_TILE)
        ratings = crest;
    if (sSurf->pose <= 7)
        rating = ratings[sSurf->pose - 1];
    if (rating == 3)
    {
        sSurf->speed = INITIAL_SPEED;
        sSurf->riderState = CRASHED;
        sSurf->stateTimer = 96;
        sSurf->flips = 0;
        sSurf->flipFlags = 0;
        PlaySE(SE_SURFING_CRASH);
        return;
    }
    PlaySE(SE_SURFING_LAND);
    sSurf->speed = max(0, (s16)sSurf->speed - rating * 64);
    if (sSurf->flips)
    {
        u16 bonus = sSameFlipScores[sSurf->flips];
        if (sSurf->flipFlags == 3)
            bonus = sSurf->flips >= 3 ? 500 : 180;
        sSurf->radness = min(MAX_SCORE, sSurf->radness + bonus);
        SpawnBonus(bonus);
        PlaySE(SE_SURFING_FLIP);
    }
    sSurf->riderState = LANDING;
    sSurf->stateTimer = 8;
}

static void UpdateRider(void)
{
    u32 worldX = (sSurf->scroll >> 8) + SURFER_X;
    u8 terrain;
    s16 height = SurfaceHeight(worldX, &terrain);
    if (sSurf->riderState == JUMPING)
    {
        RotateBoard();
        if (!sSurf->descending)
        {
            if (sSurf->jumpMagnitude == 0)
                sSurf->descending = TRUE;
            else
            {
                sSurf->jumpMagnitude -= 128;
                u32 magnitude = sSurf->jumpMagnitude >> 8;
                sSurf->surferY -= 4 * magnitude * magnitude;
            }
        }
        else if (sSurf->surferY >= height * 256)
        {
            sSurf->surferY = height * 256;
            Land(terrain);
        }
        else
        {
            sSurf->jumpMagnitude += 128;
            u32 magnitude = sSurf->jumpMagnitude >> 8;
            sSurf->surferY += 4 * magnitude * magnitude;
        }
        return;
    }
    sSurf->surferY = height * 256;
    if (sSurf->riderState == LANDING || sSurf->riderState == CRASHED)
    {
        if (--sSurf->stateTimer == 0)
        {
            if (sSurf->riderState == CRASHED)
                sSurf->pose = 4;
            sSurf->riderState = RIDING;
        }
        return;
    }
    sSurf->pose = terrain == RISING_TILE || terrain == CREST_TILE ? 6 : terrain == FALLING_TILE ? 2 : 4;
    if (terrain == CREST_TILE && worldX % 8 >= 3 && worldX % 8 < 5 && (sSurf->speed >> 5) >= 10)
    {
        sSurf->riderState = JUMPING;
        sSurf->jumpMagnitude = (sSurf->speed >> 5) * 256;
        sSurf->descending = FALSE;
        sSurf->flips = 0;
        sSurf->flipFlags = 0;
        sSurf->leftFrames = 0;
        sSurf->rightFrames = 0;
        PlaySE(SE_SURFING_JUMP);
    }
    else
        sSurf->speed = min(MAX_SPEED, sSurf->speed + 2);
}

static void ScrollWater(u16 speed, bool32 generateWaves)
{
    u32 oldSlice = sSurf->scroll >> 12;
    sSurf->scroll += speed;
    if ((sSurf->scroll >> 12) != oldSlice)
    {
        // Generate a pair of columns just beyond the right edge of the viewport.
        u8 column = (((sSurf->scroll >> 12) * 2) + 30) % WORLD_COLUMNS;
        DrawWaveSlice(column, generateWaves ? NextWavePattern() : 0);
        CopyBgTilemapBufferToVram(1);
    }
    ChangeBgX(1, sSurf->scroll & 0x1FFFF, BG_COORD_SET);
}

static void UpdateWake(void)
{
    struct Sprite *spray = &gSprites[sSurf->spraySprite];
    u8 terrain;

    // One attached graphic blinks on the water; nothing is left behind.
    spray->invisible = (sSurf->riderState != RIDING && sSurf->riderState != LANDING)
                    || (sSurf->animationFrame & 4) != 0;
    spray->x = SURFER_X;
    spray->y = SurfaceHeight((sSurf->scroll >> 8) + SURFER_X + 8, &terrain);
}

static void UpdateRun(void)
{
    sSurf->frames++;
    UpdateRider();
    UpdateWake();
    ScrollWater(384, TRUE); // 1.5 pixels/frame, independently of speed.
    sSurf->distance += sSurf->speed;
    sSurf->hp--;
    if (sSurf->distance >= COURSE_LENGTH)
    {
        DrawHud(); // Show the marker reaching shore on the completion frame.
        FinishRun(TRUE);
    }
    else if (sSurf->hp == 0)
        FinishRun(FALSE);
    else if (sSurf->frames % 6 == 0)
        DrawHud();
}

static void UpdateCoast(void)
{
    sSurf->frames++;
    sSurf->sceneFrame++;
    UpdateRider();
    UpdateWake();
    ScrollWater(9 * 256, FALSE);
    if (sSurf->sceneFrame >= 192)
    {
        sSurf->screen = SCREEN_BEACH;
        sSurf->sceneFrame = 0;
        sSurf->bonusAge = 0;
        gSprites[sSurf->spraySprite].invisible = TRUE;
        sSurf->riderState = RIDING;
        sSurf->pose = 4;
        ClearWindowTilemap(WIN_HUD);
        CopyWindowToVram(WIN_HUD, COPYWIN_MAP);
        DrawBeach(FALSE);
        ChangeBgX(1, 192 * 256, BG_COORD_SET);
    }
}

static void UpdateMusicTempo(void)
{
    // Yellow's table is indexed by floor(speed / 0.5) in 8.8 fixed point.
    static const u16 tempos[] = { 117, 109, 101, 93, 85 };
    u16 scale = 256;

    if (sSurf->screen == SCREEN_PAUSE)
        return;
    if (sSurf->screen == SCREEN_PLAY || sSurf->screen == SCREEN_START)
    {
        // Like Yellow, change tempo at a shared note boundary, so sustained
        // notes keep their current timing rather than changing mid-note.
        if (gMPlayInfo_BGM.trackCount < 3 || gMPlayInfo_BGM.tracks == NULL)
            return;
        for (u32 i = 0; i < 3; i++)
            if (gMPlayInfo_BGM.tracks[i].wait != 1)
                return;
        scale = (256 * 117 + tempos[min(4, sSurf->speed >> 7)] / 2) / tempos[min(4, sSurf->speed >> 7)];
    }
    if (gMPlayInfo_BGM.tempoU != scale)
        m4aMPlayTempoControl(&gMPlayInfo_BGM, scale);
}

static void CB2_Surfing(void)
{
    if (!gPaletteFade.active)
    {
        if (sSurf->screen != SCREEN_PAUSE && sSurf->screen != SCREEN_EXIT)
            UpdateEffects();
        switch (sSurf->screen)
        {
        case SCREEN_INTRO:
            if (JOY_NEW(B_BUTTON))
                BeginExit();
            else if (JOY_NEW(A_BUTTON | START_BUTTON) || ++sSurf->sceneFrame >= (DISPLAY_WIDTH + 32 - SURFER_X) * 2)
                StartRun();
            break;
        case SCREEN_START:
            if (++sSurf->sceneFrame >= 64)
                sSurf->screen = SCREEN_PLAY;
            break;
        case SCREEN_PLAY:
            if (JOY_NEW(START_BUTTON))
            {
                sSurf->screen = SCREEN_PAUSE;
                ShowOverlay(sTextPaused);
            }
            else
                UpdateRun();
            break;
        case SCREEN_PAUSE:
            if (JOY_NEW(B_BUTTON))
                BeginExit();
            else if (JOY_NEW(A_BUTTON | START_BUTTON))
            {
                HideOverlay();
                sSurf->screen = SCREEN_PLAY;
            }
            break;
        case SCREEN_COAST:
            UpdateCoast();
            break;
        case SCREEN_BEACH:
            sSurf->sceneFrame++;
            ChangeBgX(1, max(0, 192 - sSurf->sceneFrame * 4) * 256, BG_COORD_SET);
            if (sSurf->sceneFrame >= 80)
                ShowResults();
            break;
        case SCREEN_GAMEOVER:
        {
            u8 terrain;
            sSurf->surferY = SurfaceHeight((sSurf->scroll >> 8) + SURFER_X, &terrain) * 256;
            if (sSurf->riderState == CRASHED && sSurf->stateTimer)
                sSurf->stateTimer--;
            ScrollWater(384, FALSE);
            if (++sSurf->sceneFrame == 128)
            {
                SetWindowAttribute(WIN_HUD, WINDOW_PALETTE_NUM, 15);
                PutWindowTilemap(WIN_HUD);
                FillWindowPixelBuffer(WIN_HUD, PIXEL_FILL(1));
                Print(WIN_HUD, 4, 0, sTextGameOver);
                Print(WIN_HUD, 4, 12, sTextReturn);
                CopyWindowToVram(WIN_HUD, COPYWIN_FULL);
            }
            if (sSurf->sceneFrame >= 128)
            {
                // Saturate before a retry resets the scene timer.
                sSurf->sceneFrame = 128;
                if (JOY_NEW(A_BUTTON))
                    StartRun();
                else if (JOY_NEW(B_BUTTON))
                    BeginExit();
            }
            break;
        }
        case SCREEN_RESULTS:
            if (sSurf->tallyPhase < 8)
                UpdateResults();
            else if (JOY_NEW(B_BUTTON))
                BeginExit();
            else if (JOY_NEW(A_BUTTON))
                StartRun();
            break;
        case SCREEN_EXIT:
            SetVBlankCallback(NULL);
            ScanlineEffect_Stop();
            ScanlineEffect_Clear();
            FreeAllWindowBuffers();
            UnsetBgTilemapBuffer(0);
            UnsetBgTilemapBuffer(1);
            ResetSpriteData();
            FreeAllSpritePalettes();
            Free(sSurf);
            sSurf = NULL;
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            return;
        }
    }
    UpdateMusicTempo();
    UpdateRippleBuffer(gScanlineEffect.srcBuffer);
    AnimateSprites();
    UpdateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
