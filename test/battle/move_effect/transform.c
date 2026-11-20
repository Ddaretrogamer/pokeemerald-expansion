#include "global.h"
#include "test/battle.h"
#include "palette.h"
#include "util.h"
#include "constants/rgb.h"

TO_DO_BATTLE_TEST("TODO: Write Transform (Move Effect) test titles")

SINGLE_BATTLE_TEST("Transform uses the target's shiny palette regardless of Ditto's shininess")
{
    u32 dittoShiny, targetShiny;
    PARAMETRIZE { dittoShiny = FALSE; targetShiny = FALSE; }
    PARAMETRIZE { dittoShiny = FALSE; targetShiny = TRUE; }
    PARAMETRIZE { dittoShiny = TRUE; targetShiny = FALSE; }
    PARAMETRIZE { dittoShiny = TRUE; targetShiny = TRUE; }

    GIVEN {
        ASSUME(B_TRANSFORM_SHINY >= GEN_4);
        PLAYER(SPECIES_DITTO);
        OPPONENT(SPECIES_PIKACHU);
        SetMonData(&gBattleTestRunnerState->data.recordedBattle.playerParty[0], MON_DATA_IS_SHINY, &dittoShiny);
        SetMonData(&gBattleTestRunnerState->data.recordedBattle.opponentParty[0], MON_DATA_IS_SHINY, &targetShiny);
    } WHEN {
        TURN { MOVE(player, MOVE_TRANSFORM); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, player);
    } THEN {
        const u16 *palette = GetMonSpritePalFromSpeciesAndPersonality(SPECIES_PIKACHU, targetShiny, GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY));
        LoadPalette(palette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        BlendPalette(BG_PLTT_ID(15), 16, 6, RGB_WHITE);
        EXPECT(memcmp(&gPlttBufferUnfaded[OBJ_PLTT_ID(0)], &gPlttBufferFaded[BG_PLTT_ID(15)], PLTT_SIZE_4BPP) == 0);
    }
}

SINGLE_BATTLE_TEST("(TERA) Transform does not copy the target's Tera Type, and if the user is Terastallized it keeps its own Tera Type")
{
    u32 playerDoTera;
    PARAMETRIZE { playerDoTera = GIMMICK_TERA; }
    PARAMETRIZE { playerDoTera = GIMMICK_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE, MOVE_SCRATCH, MOVE_EARTHQUAKE); TeraType(TYPE_GHOST); }
        OPPONENT(SPECIES_DITTO) { TeraType(TYPE_FLYING); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: playerDoTera); MOVE(opponent, MOVE_TRANSFORM); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, moveSlot: 0); }
        TURN { MOVE(player, MOVE_EARTHQUAKE); MOVE(opponent, moveSlot: 0, gimmick: GIMMICK_TERA); }
    } SCENE {
        // turn 1
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRANSFORM, opponent);
        // turn 2
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        // turn 3
        MESSAGE("Wobbuffet used Earthquake!");
        MESSAGE("It doesn't affect the opposing Ditto…");
        NOT { HP_BAR(opponent); }
    }
}
