daycarebase_MapScripts::
# 2 "data/maps/daycarebase/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Daycare_OnTransition
# 3 "data/maps/daycarebase/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, daycarebase_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

daycarebase_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/daycarebase/scripts.pory"
	map_script_2 VAR_INTRO_PLAYED, 0, DaycareIntro
	.2byte 0


DaycareIntro::
# 7 "data/maps/daycarebase/scripts.pory"
	lock
# 8 "data/maps/daycarebase/scripts.pory"
	special EnableNationalPokedex
# 9 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 10 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareIntro_Text_1, MSGBOX_AUTOCLOSE
# 11 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 12 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_OLDMAN_INTRO
# 13 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareManIntro, DaycareIntro_Movement_0
# 14 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareManIntro
# 15 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareManIntro, DaycareIntro_Movement_1
# 16 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareManIntro
# 17 "data/maps/daycarebase/scripts.pory"
	removeobject DaycareManIntro
# 18 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_INTRO_DAYCAREMAN
# 19 "data/maps/daycarebase/scripts.pory"
	applymovement LOCALID_PLAYER, DaycareIntro_Movement_2
# 20 "data/maps/daycarebase/scripts.pory"
	applymovement VaporeonIntro, DaycareIntro_Movement_3
# 21 "data/maps/daycarebase/scripts.pory"
	waitmovement LOCALID_PLAYER
# 22 "data/maps/daycarebase/scripts.pory"
	waitmovement VaporeonIntro
# 23 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 24 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 25 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareIntro_Text_3, MSGBOX_AUTOCLOSE
# 25 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 26 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 27 "data/maps/daycarebase/scripts.pory"
	applymovement VaporeonIntro, DaycareIntro_Movement_4
# 28 "data/maps/daycarebase/scripts.pory"
	playse SE_FLEE
# 29 "data/maps/daycarebase/scripts.pory"
	waitmovement VaporeonIntro
# 30 "data/maps/daycarebase/scripts.pory"
	waitse
# 31 "data/maps/daycarebase/scripts.pory"
	removeobject VaporeonIntro
# 32 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_VAPOREON_INTRO
# 33 "data/maps/daycarebase/scripts.pory"
	setvar VAR_INTRO_PLAYED, 1
# 34 "data/maps/daycarebase/scripts.pory"
	release
	end


Daycare_OnTransition::
# 39 "data/maps/daycarebase/scripts.pory"
	setrespawn HEAL_LOCATION_DAYCAREBASE
	end


ShrinkToPikachuCave::
# 44 "data/maps/daycarebase/scripts.pory"
	lock
# 45 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave_1
# 59 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave_4
ShrinkToPikachuCave_3:
# 88 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 89 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 90 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_1:
# 47 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 48 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave_8
# 54 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 55 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_2:
# 61 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 62 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave_11
# 80 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 81 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 82 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_4:
# 59 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave_2
	goto ShrinkToPikachuCave_3

ShrinkToPikachuCave_8:
# 50 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 0
	return

ShrinkToPikachuCave_11:
# 64 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 65 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave_14
# 73 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 74 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave_14:
# 67 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 68 "data/maps/daycarebase/scripts.pory"
	delay 30
# 69 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 0
	return


ShrinkToPikachuCave2::
# 96 "data/maps/daycarebase/scripts.pory"
	lock
# 97 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave2_1
# 111 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave2_4
ShrinkToPikachuCave2_3:
# 140 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 141 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 142 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_1:
# 99 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 100 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave2_8
# 106 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 107 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_2:
# 113 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 114 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave2_11
# 132 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 133 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 134 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_4:
# 111 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave2_2
	goto ShrinkToPikachuCave2_3

ShrinkToPikachuCave2_8:
# 102 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 1
	return

ShrinkToPikachuCave2_11:
# 116 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 117 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave2_14
# 125 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 126 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinkToPikachuCave2_14:
# 119 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 120 "data/maps/daycarebase/scripts.pory"
	delay 30
# 121 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_PIKACHU_SHRINK_CAVE, 1
	return


ShrinktoMausholdCave::
# 148 "data/maps/daycarebase/scripts.pory"
	lock
# 149 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinktoMausholdCave_1
# 163 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinktoMausholdCave_4
ShrinktoMausholdCave_3:
# 192 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 193 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 194 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_1:
# 151 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_0, MSGBOX_YESNO
# 152 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinktoMausholdCave_8
# 158 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 159 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_2:
# 165 "data/maps/daycarebase/scripts.pory"
	checkpartymove MOVE_DAZZLING_GLEAM
# 166 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinktoMausholdCave_11
# 184 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_2, MSGBOX_DEFAULT
# 185 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 186 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_4:
# 163 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinktoMausholdCave_2
	goto ShrinktoMausholdCave_3

ShrinktoMausholdCave_8:
# 154 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_MAUSHOLD_SHRINK, 0
	return

ShrinktoMausholdCave_11:
# 168 "data/maps/daycarebase/scripts.pory"
	msgbox ShrinkToPikachuCave_Text_1, MSGBOX_YESNO
# 169 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinktoMausholdCave_14
# 177 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 178 "data/maps/daycarebase/scripts.pory"
	release
	end

ShrinktoMausholdCave_14:
# 171 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 172 "data/maps/daycarebase/scripts.pory"
	delay 30
# 173 "data/maps/daycarebase/scripts.pory"
	warp MAP_DAYCARE_MAUSHOLD_SHRINK, 0
	return


MimikyuDialog::
# 200 "data/maps/daycarebase/scripts.pory"
	lock
# 201 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, MimikyuDialog_Movement_0
# 202 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 203 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq MimikyuDialog_1
# 220 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_PIKACHU
	goto_if_eq MimikyuDialog_2
# 256 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 257 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 258 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 259 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 260 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 261 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_1:
# 205 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 206 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 207 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 208 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 209 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 210 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, Common_Movement_ExclamationMark
# 211 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 212 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 213 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 214 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_3, MSGBOX_DEFAULT
# 215 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 216 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 217 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_2:
# 222 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_MIMIKYU_LUCKYEGG, MimikyuDialog_6
# 234 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 235 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYUTOP, EMOTE_NORMAL
# 236 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_1, MSGBOX_DEFAULT
# 237 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 238 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 239 "data/maps/daycarebase/scripts.pory"
	applymovement mimikyu, Common_Movement_ExclamationMark
# 240 "data/maps/daycarebase/scripts.pory"
	waitmovement mimikyu
# 241 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 242 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 243 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_5, MSGBOX_DEFAULT
# 244 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 245 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 246 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 247 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 248 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_MIMIKYU_LUCKYEGG
# 249 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 250 "data/maps/daycarebase/scripts.pory"
	release
	end

MimikyuDialog_6:
# 224 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_2
# 225 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_MIMIKYU, EMOTE_ANGRY
# 226 "data/maps/daycarebase/scripts.pory"
	msgbox MimikyuDialog_Text_4, MSGBOX_DEFAULT
# 227 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 228 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 229 "data/maps/daycarebase/scripts.pory"
	release
	end


KecleonDialog::
# 266 "data/maps/daycarebase/scripts.pory"
	lock
# 267 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 268 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq KecleonDialog_1
# 280 "data/maps/daycarebase/scripts.pory"
	speakername KecleonDialog_Text_0
# 281 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_KECLEON, EMOTE_NORMAL
# 282 "data/maps/daycarebase/scripts.pory"
	msgbox KecleonDialog_Text_2, MSGBOX_DEFAULT
# 283 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 284 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 285 "data/maps/daycarebase/scripts.pory"
	release
	end

KecleonDialog_1:
# 270 "data/maps/daycarebase/scripts.pory"
	speakername KecleonDialog_Text_0
# 271 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_KECLEON, EMOTE_NORMAL
# 272 "data/maps/daycarebase/scripts.pory"
	msgbox KecleonDialog_Text_1, MSGBOX_DEFAULT
# 273 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 274 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 275 "data/maps/daycarebase/scripts.pory"
	release
	end


AzumarillDialog::
# 292 "data/maps/daycarebase/scripts.pory"
	lock
# 293 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 294 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq AzumarillDialog_1
# 306 "data/maps/daycarebase/scripts.pory"
	speakername AzumarillDialog_Text_0
# 307 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_AZUMARILL, EMOTE_ANGRY
# 308 "data/maps/daycarebase/scripts.pory"
	msgbox AzumarillDialog_Text_2, MSGBOX_DEFAULT
# 309 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 310 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 311 "data/maps/daycarebase/scripts.pory"
	release
	end

AzumarillDialog_1:
# 296 "data/maps/daycarebase/scripts.pory"
	speakername AzumarillDialog_Text_0
# 297 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_AZUMARILL, EMOTE_NORMAL
# 298 "data/maps/daycarebase/scripts.pory"
	msgbox AzumarillDialog_Text_1, MSGBOX_DEFAULT
# 299 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 300 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 301 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareOldManDialog::
# 317 "data/maps/daycarebase/scripts.pory"
	lock
# 318 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 319 "data/maps/daycarebase/scripts.pory"
	goto_if_unset FLAG_BEAT_MEW, DaycareOldManDialog_1
# 351 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq DaycareOldManDialog_7
# 587 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 588 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_1, MSGBOX_DEFAULT
# 589 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 590 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_1:
# 321 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_OLDMAN_INTRO, DaycareOldManDialog_4
# 341 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 342 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_2, MSGBOX_DEFAULT
# 343 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 344 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_OLDMAN_INTRO
# 345 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_4:
# 323 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq DaycareOldManDialog_10
# 332 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 333 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_1, MSGBOX_DEFAULT
# 334 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 335 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_7:
# 353 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 354 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 355 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, MimikyuDialog_Movement_0
# 356 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 357 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, Common_Movement_ExclamationMark
# 358 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 359 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 360 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_3, MSGBOX_YESNO
# 361 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 362 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareOldManDialog_13
# 475 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 476 "data/maps/daycarebase/scripts.pory"
	playse SE_M_SCRATCH
# 477 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_15, MSGBOX_DEFAULT
# 478 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 479 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 480 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 481 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_5, MSGBOX_DEFAULT
# 482 "data/maps/daycarebase/scripts.pory"
	removeobject BrendanBiking
# 483 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_BRENDAN_BIKE
# 484 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 485 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 486 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP
# 487 "data/maps/daycarebase/scripts.pory"
	waitse
# 488 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP_MAX
# 489 "data/maps/daycarebase/scripts.pory"
	waitse
# 490 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 491 "data/maps/daycarebase/scripts.pory"
	callnative Script_GiveFirstMonLevel
# 492 "data/maps/daycarebase/scripts.pory"
	specialvar VAR_RESULT, GetDittoLevel
# 493 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 494 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_6, MSGBOX_DEFAULT
# 495 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 496 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_AIR_BALLOON, 1
# 497 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 498 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 499 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_7, MSGBOX_AUTOCLOSE
# 500 "data/maps/daycarebase/scripts.pory"
	special SpawnCameraObject
# 501 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_0
# 502 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 503 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_1
# 504 "data/maps/daycarebase/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, DaycareOldManDialog_Movement_1
# 505 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 506 "data/maps/daycarebase/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 507 "data/maps/daycarebase/scripts.pory"
	delay 60
# 508 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK, 24
# 509 "data/maps/daycarebase/scripts.pory"
	delay 60
# 510 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SHOW_BRENDAN_OUTRO
# 511 "data/maps/daycarebase/scripts.pory"
	addobject Brendan
# 512 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK, 24
# 513 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_2
# 514 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 515 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 516 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, Common_Movement_ExclamationMark
# 517 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 518 "data/maps/daycarebase/scripts.pory"
	delay 30
# 519 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_3
# 520 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 521 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_4
# 522 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 523 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 524 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_8, MSGBOX_DEFAULT
# 525 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 526 "data/maps/daycarebase/scripts.pory"
	delay 30
# 527 "data/maps/daycarebase/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 528 "data/maps/daycarebase/scripts.pory"
	delay 60
# 529 "data/maps/daycarebase/scripts.pory"
	special CountLuckyEggs
# 530 "data/maps/daycarebase/scripts.pory"
	special GetWhiteoutCount
# 531 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_WHITEOUT_COUNT
# 532 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_0
# 533 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_1, VAR_LUCKYEGG_COUNT
# 534 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_1
# 535 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_61
DaycareOldManDialog_58:
# 549 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_57
DaycareOldManDialog_54:
# 555 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_53
DaycareOldManDialog_51:
# 561 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_50
DaycareOldManDialog_48:
# 567 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_47
DaycareOldManDialog_46:
# 575 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_14, MSGBOX_DEFAULT
# 576 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 577 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
DaycareOldManDialog_40:
# 579 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 580 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 581 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 582 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 583 "data/maps/daycarebase/scripts.pory"
	special GameClear
	return

DaycareOldManDialog_10:
# 325 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 326 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_0, MSGBOX_DEFAULT
# 327 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 328 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_13:
# 364 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 365 "data/maps/daycarebase/scripts.pory"
	playse SE_ITEMFINDER
# 366 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_4, MSGBOX_DEFAULT
# 367 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 368 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 369 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 370 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_5, MSGBOX_DEFAULT
# 371 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 372 "data/maps/daycarebase/scripts.pory"
	removeobject BrendanBiking
# 373 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_HIDE_BRENDAN_BIKE
# 374 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 375 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP
# 376 "data/maps/daycarebase/scripts.pory"
	waitse
# 377 "data/maps/daycarebase/scripts.pory"
	playse SE_EXP_MAX
# 378 "data/maps/daycarebase/scripts.pory"
	waitse
# 379 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 380 "data/maps/daycarebase/scripts.pory"
	callnative Script_GiveFirstMonLevel
# 381 "data/maps/daycarebase/scripts.pory"
	specialvar VAR_RESULT, GetDittoLevel
# 382 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_RESULT
# 383 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_6, MSGBOX_DEFAULT
# 384 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 385 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_AIR_BALLOON, 1
# 386 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 387 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 388 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_7, MSGBOX_AUTOCLOSE
# 389 "data/maps/daycarebase/scripts.pory"
	special SpawnCameraObject
# 390 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_0
# 391 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 392 "data/maps/daycarebase/scripts.pory"
	applymovement DaycareMan, DaycareOldManDialog_Movement_1
# 393 "data/maps/daycarebase/scripts.pory"
	applymovement OBJ_EVENT_ID_CAMERA, DaycareOldManDialog_Movement_1
# 394 "data/maps/daycarebase/scripts.pory"
	waitmovement DaycareMan
# 395 "data/maps/daycarebase/scripts.pory"
	waitmovement OBJ_EVENT_ID_CAMERA
# 396 "data/maps/daycarebase/scripts.pory"
	delay 60
# 397 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK, 24
# 398 "data/maps/daycarebase/scripts.pory"
	delay 60
# 399 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SHOW_BRENDAN_OUTRO
# 400 "data/maps/daycarebase/scripts.pory"
	addobject Brendan
# 401 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK, 24
# 402 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_2
# 403 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 404 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 405 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, Common_Movement_ExclamationMark
# 406 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 407 "data/maps/daycarebase/scripts.pory"
	delay 30
# 408 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_3
# 409 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 410 "data/maps/daycarebase/scripts.pory"
	applymovement Brendan, DaycareOldManDialog_Movement_4
# 411 "data/maps/daycarebase/scripts.pory"
	waitmovement Brendan
# 412 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_0
# 413 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_8, MSGBOX_DEFAULT
# 414 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 415 "data/maps/daycarebase/scripts.pory"
	delay 30
# 416 "data/maps/daycarebase/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 417 "data/maps/daycarebase/scripts.pory"
	delay 60
# 418 "data/maps/daycarebase/scripts.pory"
	special CountLuckyEggs
# 419 "data/maps/daycarebase/scripts.pory"
	special GetWhiteoutCount
# 420 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_WHITEOUT_COUNT
# 421 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TEMP_0
# 422 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_1, VAR_LUCKYEGG_COUNT
# 423 "data/maps/daycarebase/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_1
# 424 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_37
DaycareOldManDialog_34:
# 438 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_33
DaycareOldManDialog_30:
# 444 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_eq DaycareOldManDialog_29
DaycareOldManDialog_27:
# 450 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_26
DaycareOldManDialog_24:
# 456 "data/maps/daycarebase/scripts.pory"
	compare VAR_WHITEOUT_COUNT, 0
	goto_if_ne DaycareOldManDialog_23
DaycareOldManDialog_22:
# 464 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_14, MSGBOX_DEFAULT
# 465 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 466 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
DaycareOldManDialog_16:
# 468 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 469 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 470 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 471 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 472 "data/maps/daycarebase/scripts.pory"
	special GameClear
	return

DaycareOldManDialog_17:
# 426 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_9, MSGBOX_DEFAULT
# 427 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 428 "data/maps/daycarebase/scripts.pory"
	special ForceShinyDitto
# 429 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 430 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 431 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 432 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 433 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 434 "data/maps/daycarebase/scripts.pory"
	warp MAP_ROUTE117, 14, 27
# 435 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_18:
# 440 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_10, MSGBOX_DEFAULT
# 441 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 442 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_19:
# 446 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_11, MSGBOX_DEFAULT
# 447 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 448 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_20:
# 452 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_12, MSGBOX_DEFAULT
# 453 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 454 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_21:
# 458 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_13, MSGBOX_DEFAULT
# 459 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 460 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_16

DaycareOldManDialog_23:
# 456 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_21
	goto DaycareOldManDialog_22

DaycareOldManDialog_26:
# 450 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_20
	goto DaycareOldManDialog_24

DaycareOldManDialog_29:
# 444 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_19
	goto DaycareOldManDialog_27

DaycareOldManDialog_32:
# 438 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_gt DaycareOldManDialog_18
	goto DaycareOldManDialog_30

DaycareOldManDialog_33:
# 438 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_ne DaycareOldManDialog_32
	goto DaycareOldManDialog_30

DaycareOldManDialog_37:
# 424 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_17
	goto DaycareOldManDialog_34

DaycareOldManDialog_41:
# 537 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_9, MSGBOX_DEFAULT
# 538 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 539 "data/maps/daycarebase/scripts.pory"
	special ForceShinyDitto
# 540 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 541 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_BEAT_MEW
# 542 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SHOW_BRENDAN_OUTRO
# 543 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_HIDE_BRENDAN_BIKE
# 544 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SPAWN_INVISIBLE
# 545 "data/maps/daycarebase/scripts.pory"
	warp MAP_ROUTE117, 14, 27
# 546 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareOldManDialog_42:
# 551 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_10, MSGBOX_DEFAULT
# 552 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 553 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_43:
# 557 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_11, MSGBOX_DEFAULT
# 558 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 559 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_44:
# 563 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_12, MSGBOX_DEFAULT
# 564 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 565 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_45:
# 569 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareOldManDialog_Text_13, MSGBOX_DEFAULT
# 570 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 571 "data/maps/daycarebase/scripts.pory"
	special RemoveForceShinyDitto
	goto DaycareOldManDialog_40

DaycareOldManDialog_47:
# 567 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_45
	goto DaycareOldManDialog_46

DaycareOldManDialog_50:
# 561 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_44
	goto DaycareOldManDialog_48

DaycareOldManDialog_53:
# 555 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_eq DaycareOldManDialog_43
	goto DaycareOldManDialog_51

DaycareOldManDialog_56:
# 549 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 0
	goto_if_gt DaycareOldManDialog_42
	goto DaycareOldManDialog_54

DaycareOldManDialog_57:
# 549 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_ne DaycareOldManDialog_56
	goto DaycareOldManDialog_54

DaycareOldManDialog_61:
# 535 "data/maps/daycarebase/scripts.pory"
	compare VAR_LUCKYEGG_COUNT, 18
	goto_if_eq DaycareOldManDialog_41
	goto DaycareOldManDialog_58


VaporeonDialog::
# 601 "data/maps/daycarebase/scripts.pory"
	lock
# 602 "data/maps/daycarebase/scripts.pory"
	applymovement vaporeonswimming, MimikyuDialog_Movement_0
# 603 "data/maps/daycarebase/scripts.pory"
	waitmovement vaporeonswimming
# 604 "data/maps/daycarebase/scripts.pory"
	goto_if_unset FLAG_BEAT_MEW, VaporeonDialog_1
# 616 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 617 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 618 "data/maps/daycarebase/scripts.pory"
	msgbox VaporeonDialog_Text_1, MSGBOX_NPC
# 619 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 620 "data/maps/daycarebase/scripts.pory"
	applymovement vaporeonswimming, Common_Movement_ExclamationMark
# 621 "data/maps/daycarebase/scripts.pory"
	waitmovement vaporeonswimming
# 622 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 623 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 624 "data/maps/daycarebase/scripts.pory"
	msgbox VaporeonDialog_Text_2, MSGBOX_NPC
# 624 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 625 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 626 "data/maps/daycarebase/scripts.pory"
	release
	return

VaporeonDialog_1:
# 606 "data/maps/daycarebase/scripts.pory"
	speakername DaycareIntro_Text_2
# 607 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_VAPOREON, EMOTE_ANGRY
# 608 "data/maps/daycarebase/scripts.pory"
	msgbox VaporeonDialog_Text_0, MSGBOX_NPC
# 609 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 610 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 611 "data/maps/daycarebase/scripts.pory"
	release
	end


LaprasDialog::
# 632 "data/maps/daycarebase/scripts.pory"
	lock
# 633 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 634 "data/maps/daycarebase/scripts.pory"
	speakername LaprasDialog_Text_0
# 635 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LAPRAS, EMOTE_HAPPY
# 636 "data/maps/daycarebase/scripts.pory"
	msgbox LaprasDialog_Text_1, MSGBOX_DEFAULT
# 637 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 638 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 639 "data/maps/daycarebase/scripts.pory"
	release
	end


LinooneDialog::
# 644 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq LinooneDialog_1
# 658 "data/maps/daycarebase/scripts.pory"
	lock
# 659 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 660 "data/maps/daycarebase/scripts.pory"
	speakername LinooneDialog_Text_0
# 661 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LINOONE, EMOTE_NORMAL
# 662 "data/maps/daycarebase/scripts.pory"
	msgbox LinooneDialog_Text_2
# 663 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 664 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 665 "data/maps/daycarebase/scripts.pory"
	release
	end

LinooneDialog_1:
# 646 "data/maps/daycarebase/scripts.pory"
	lock
# 647 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 648 "data/maps/daycarebase/scripts.pory"
	speakername LinooneDialog_Text_0
# 649 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_LINOONE, EMOTE_NORMAL
# 650 "data/maps/daycarebase/scripts.pory"
	msgbox LinooneDialog_Text_1
# 651 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 652 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 653 "data/maps/daycarebase/scripts.pory"
	release
	end


BulbsaurDialog::
# 671 "data/maps/daycarebase/scripts.pory"
	lock
# 672 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 673 "data/maps/daycarebase/scripts.pory"
	speakername BulbsaurDialog_Text_0
# 674 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_BULBASAUR, EMOTE_NORMAL
# 675 "data/maps/daycarebase/scripts.pory"
	msgbox BulbsaurDialog_Text_1, MSGBOX_NPC
# 676 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 677 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 678 "data/maps/daycarebase/scripts.pory"
	release
	end


CombeeDialog::
# 683 "data/maps/daycarebase/scripts.pory"
	lock
# 684 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 685 "data/maps/daycarebase/scripts.pory"
	speakername CombeeDialog_Text_0
# 686 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_COMBEE, EMOTE_NORMAL
# 687 "data/maps/daycarebase/scripts.pory"
	msgbox CombeeDialog_Text_1, MSGBOX_NPC
# 688 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 689 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 690 "data/maps/daycarebase/scripts.pory"
	release
	end


Porygon2Dialog::
# 695 "data/maps/daycarebase/scripts.pory"
	lock
# 696 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 697 "data/maps/daycarebase/scripts.pory"
	speakername Porygon2Dialog_Text_0
# 698 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PORYGON2, EMOTE_NORMAL
# 699 "data/maps/daycarebase/scripts.pory"
	msgbox Porygon2Dialog_Text_1, MSGBOX_NPC
# 700 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 701 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 702 "data/maps/daycarebase/scripts.pory"
	release
	end


ScytherDialog::
# 707 "data/maps/daycarebase/scripts.pory"
	lock
# 708 "data/maps/daycarebase/scripts.pory"
	applymovement scyther, MimikyuDialog_Movement_0
# 709 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_DITTO_IS_SHINY, ScytherDialog_3
ScytherDialog_2:
# 725 "data/maps/daycarebase/scripts.pory"
	speakername ScytherDialog_Text_0
# 726 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_SCYTHER, EMOTE_NORMAL
# 727 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_3, MSGBOX_DEFAULT
# 728 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 729 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 730 "data/maps/daycarebase/scripts.pory"
	release
	end

ScytherDialog_1:
# 711 "data/maps/daycarebase/scripts.pory"
	speakername ScytherDialog_Text_0
# 712 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_SCYTHER, EMOTE_NORMAL
# 713 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_1, MSGBOX_DEFAULT
# 714 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 715 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 716 "data/maps/daycarebase/scripts.pory"
	applymovement scyther, Common_Movement_ExclamationMark
# 717 "data/maps/daycarebase/scripts.pory"
	waitmovement scyther
# 718 "data/maps/daycarebase/scripts.pory"
	msgbox ScytherDialog_Text_2
# 719 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 720 "data/maps/daycarebase/scripts.pory"
	release
	end

ScytherDialog_3:
# 709 "data/maps/daycarebase/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq ScytherDialog_1
	goto ScytherDialog_2


RioluDialog::
# 736 "data/maps/daycarebase/scripts.pory"
	lock
# 737 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 738 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_RIOLU_INTRO, RioluDialog_1
# 873 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 874 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 875 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_28, MSGBOX_DEFAULT
# 876 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_RIOLU_INTRO
# 877 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 878 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 879 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_1:
# 740 "data/maps/daycarebase/scripts.pory"
	lock
# 741 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 742 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 743 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 744 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_1, MSGBOX_DEFAULT
# 745 "data/maps/daycarebase/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 746 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 747 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RioluDialog_4
# 860 "data/maps/daycarebase/scripts.pory"
	lock
# 861 "data/maps/daycarebase/scripts.pory"
	speakername RioluDialog_Text_0
# 862 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 863 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_27, MSGBOX_AUTOCLOSE
# 864 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 865 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 866 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_4:
# 749 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 750 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_2, MSGBOX_DEFAULT
# 751 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 752 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_3, MSGBOX_YESNO
# 753 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RioluDialog_7
# 850 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 851 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_26
# 852 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 853 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 854 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_7:
# 755 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_RIOLU, EMOTE_NORMAL
# 756 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_4, MSGBOX_DEFAULT
# 757 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 758 "data/maps/daycarebase/scripts.pory"
	dynmultichoice 0, 0, TRUE, 5, 0, DYN_MULTICHOICE_CB_NONE, RioluDialog_Text_5, RioluDialog_Text_6, RioluDialog_Text_7, RioluDialog_Text_8, RioluDialog_Text_9, RioluDialog_Text_10, RioluDialog_Text_11, MimikyuDialog_Text_0, RioluDialog_Text_12, RioluDialog_Text_13, RioluDialog_Text_14
# 759 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq RioluDialog_10
# 767 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq RioluDialog_11
# 775 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq RioluDialog_12
# 783 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq RioluDialog_13
# 791 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq RioluDialog_14
# 799 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq RioluDialog_15
# 807 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq RioluDialog_16
# 815 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq RioluDialog_17
# 823 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq RioluDialog_18
# 831 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq RioluDialog_19
# 839 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq RioluDialog_20
	return

RioluDialog_10:
# 761 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_15, MSGBOX_DEFAULT
# 762 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 763 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 764 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_11:
# 769 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_16, MSGBOX_DEFAULT
# 770 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 771 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 772 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_12:
# 777 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_17, MSGBOX_DEFAULT
# 778 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 779 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 780 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_13:
# 785 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_18, MSGBOX_DEFAULT
# 786 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 787 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 788 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_14:
# 793 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_19, MSGBOX_DEFAULT
# 794 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 795 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 796 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_15:
# 801 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_20, MSGBOX_DEFAULT
# 802 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 803 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 804 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_16:
# 809 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_21, MSGBOX_DEFAULT
# 810 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 811 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 812 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_17:
# 817 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_22, MSGBOX_DEFAULT
# 818 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 819 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 820 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_18:
# 825 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_23, MSGBOX_DEFAULT
# 826 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 827 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 828 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_19:
# 833 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_24, MSGBOX_DEFAULT
# 834 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 835 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 836 "data/maps/daycarebase/scripts.pory"
	release
	end

RioluDialog_20:
# 841 "data/maps/daycarebase/scripts.pory"
	msgbox RioluDialog_Text_25, MSGBOX_DEFAULT
# 842 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 843 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 844 "data/maps/daycarebase/scripts.pory"
	release
	end


BattleVsPikachu::
# 886 "data/maps/daycarebase/scripts.pory"
	lock
# 888 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_TRANS_PIKACHU, BattleVsPikachu_2
# 901 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 902 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, MimikyuDialog_Movement_0
# 903 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 904 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 905 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, Common_Movement_ExclamationMark
# 906 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 907 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 908 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_NORMAL
# 909 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_1, MSGBOX_AUTOCLOSE
# 910 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 911 "data/maps/daycarebase/scripts.pory"
	setwildbattle SPECIES_PIKACHU, 25
# 912 "data/maps/daycarebase/scripts.pory"
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1, 0, 0
# 913 "data/maps/daycarebase/scripts.pory"
	dowildbattle
# 914 "data/maps/daycarebase/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 915 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BattleVsPikachu_4
	return

BattleVsPikachu_2:
# 890 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, MimikyuDialog_Movement_0
# 891 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 892 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 893 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_NORMAL
# 894 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_0, MSGBOX_DEFAULT
# 895 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 896 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 897 "data/maps/daycarebase/scripts.pory"
	release
	end

BattleVsPikachu_4:
# 917 "data/maps/daycarebase/scripts.pory"
	lock
# 918 "data/maps/daycarebase/scripts.pory"
	applymovement Pikachu, Common_Movement_ExclamationMark
# 919 "data/maps/daycarebase/scripts.pory"
	waitmovement Pikachu
# 920 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 921 "data/maps/daycarebase/scripts.pory"
	playbgm MUS_PMD_HAPPINESS, FALSE
# 922 "data/maps/daycarebase/scripts.pory"
	lock
# 923 "data/maps/daycarebase/scripts.pory"
	copyvar VAR_TEMP_0, VAR_TRANSFORM_MON
# 924 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_TRANS_PIKACHU
# 925 "data/maps/daycarebase/scripts.pory"
	delay 30
# 926 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_PIKACHU
# 927 "data/maps/daycarebase/scripts.pory"
	playse MUS_LEVEL_UP
# 928 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_2, MSGBOX_DEFAULT
# 929 "data/maps/daycarebase/scripts.pory"
	waitse
# 930 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 931 "data/maps/daycarebase/scripts.pory"
	lock
# 932 "data/maps/daycarebase/scripts.pory"
	dittotransform VAR_TEMP_0
# 933 "data/maps/daycarebase/scripts.pory"
	givemon SPECIES_PIKACHU, 25, move1 = MOVE_NUZZLE, move2 = MOVE_IRON_TAIL, move3 = MOVE_SPARK, move4 = MOVE_FLASH
# 934 "data/maps/daycarebase/scripts.pory"
	speakername MimikyuDialog_Text_0
# 935 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_PIKACHU, EMOTE_HAPPY
# 936 "data/maps/daycarebase/scripts.pory"
	msgbox BattleVsPikachu_Text_3, MSGBOX_DEFAULT
# 937 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 938 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 939 "data/maps/daycarebase/scripts.pory"
	fadenewbgm MUS_PMD_HEARTWARMING
# 940 "data/maps/daycarebase/scripts.pory"
	release
	end


ChanseyHeal::
# 946 "data/maps/daycarebase/scripts.pory"
	lock
# 947 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 948 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_CHANSEY_INTRO, ChanseyHeal_1
# 996 "data/maps/daycarebase/scripts.pory"
	lock
# 997 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 998 "data/maps/daycarebase/scripts.pory"
	speakername ChanseyHeal_Text_0
# 999 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 1000 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_6, MSGBOX_DEFAULT
# 1001 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1002 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_CHANSEY_INTRO
# 1003 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1004 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_1:
# 950 "data/maps/daycarebase/scripts.pory"
	speakername ChanseyHeal_Text_0
# 951 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 952 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_1, MSGBOX_DEFAULT
# 953 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 954 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_2, MSGBOX_YESNO
# 955 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 956 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ChanseyHeal_4
# 986 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 987 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_5, MSGBOX_AUTOCLOSE
# 988 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 989 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 990 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_4:
# 958 "data/maps/daycarebase/scripts.pory"
	checkitem ITEM_LUCKY_EGG
# 959 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ChanseyHeal_7
# 976 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_CHANSEY, EMOTE_NORMAL
# 977 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_4, MSGBOX_AUTOCLOSE
# 978 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 979 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 980 "data/maps/daycarebase/scripts.pory"
	release
	end

ChanseyHeal_7:
# 961 "data/maps/daycarebase/scripts.pory"
	removeitem ITEM_LUCKY_EGG
# 962 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 963 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 964 "data/maps/daycarebase/scripts.pory"
	playfanfare MUS_HEAL
# 965 "data/maps/daycarebase/scripts.pory"
	waitfanfare
# 966 "data/maps/daycarebase/scripts.pory"
	special HealPlayerParty
# 967 "data/maps/daycarebase/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 968 "data/maps/daycarebase/scripts.pory"
	msgbox ChanseyHeal_Text_3, MSGBOX_AUTOCLOSE
# 969 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 970 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 971 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_Ditto::
# 1011 "data/maps/daycarebase/scripts.pory"
	lock
# 1012 "data/maps/daycarebase/scripts.pory"
	faceplayer
# 1013 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_DITTO_INTRO, DaycareBase_Ditto_1
# 1053 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1054 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1055 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_4, MSGBOX_DEFAULT
# 1056 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1057 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 1058 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1059 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1060 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_1:
# 1015 "data/maps/daycarebase/scripts.pory"
	goto_if_set FLAG_XFORMS_TALKED_TO_DITTO, DaycareBase_Ditto_4
# 1041 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1042 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1043 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_3, MSGBOX_DEFAULT
# 1044 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1045 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1046 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_4:
# 1017 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_0, MSGBOX_YESNO
# 1018 "data/maps/daycarebase/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DaycareBase_Ditto_7
# 1029 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1030 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1031 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_2, MSGBOX_AUTOCLOSE
# 1032 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1033 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1034 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1035 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1036 "data/maps/daycarebase/scripts.pory"
	release
	end

DaycareBase_Ditto_7:
# 1020 "data/maps/daycarebase/scripts.pory"
	dittotransform SPECIES_DITTO
# 1021 "data/maps/daycarebase/scripts.pory"
	special OpenPCMoveMons
# 1022 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 1023 "data/maps/daycarebase/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 1024 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycarebaseDitto_intro_trigger::
# 1067 "data/maps/daycarebase/scripts.pory"
	goto_if_unset FLAG_DITTO_INTRO, DaycarebaseDitto_intro_trigger_1
	end

DaycarebaseDitto_intro_trigger_1:
# 1069 "data/maps/daycarebase/scripts.pory"
	lock
# 1070 "data/maps/daycarebase/scripts.pory"
	playse SE_PIN
# 1071 "data/maps/daycarebase/scripts.pory"
	applymovement DittoIntro, Common_Movement_ExclamationMark
# 1072 "data/maps/daycarebase/scripts.pory"
	waitmovement DittoIntro
# 1073 "data/maps/daycarebase/scripts.pory"
	applymovement DittoIntro, DaycareIntro_Movement_2
# 1074 "data/maps/daycarebase/scripts.pory"
	waitmovement DittoIntro
# 1075 "data/maps/daycarebase/scripts.pory"
	applymovement LOCALID_PLAYER, DaycareIntro_Movement_3
# 1076 "data/maps/daycarebase/scripts.pory"
	waitmovement LOCALID_PLAYER
# 1077 "data/maps/daycarebase/scripts.pory"
	speakername DaycareBase_Ditto_Text_1
# 1078 "data/maps/daycarebase/scripts.pory"
	createfieldmugshot MUGSHOT_DITTO, EMOTE_NORMAL
# 1079 "data/maps/daycarebase/scripts.pory"
	msgbox DaycareBase_Ditto_Text_4, MSGBOX_DEFAULT
# 1080 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1081 "data/maps/daycarebase/scripts.pory"
	removefieldmugshot
# 1082 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_DITTO_INTRO
# 1083 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_FindLuckyEgg::
# 1093 "data/maps/daycarebase/scripts.pory"
	finditem ITEM_LUCKY_EGG
	return


DaycareBase_FindLuckyEgg1::
# 1097 "data/maps/daycarebase/scripts.pory"
	lock
# 1098 "data/maps/daycarebase/scripts.pory"
	removeobject luckyegg1
# 1099 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 1100 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1101 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_BASE1
# 1102 "data/maps/daycarebase/scripts.pory"
	release
	end


DaycareBase_FindLuckyEgg2::
# 1107 "data/maps/daycarebase/scripts.pory"
	lock
# 1108 "data/maps/daycarebase/scripts.pory"
	removeobject luckyegg2
# 1109 "data/maps/daycarebase/scripts.pory"
	giveitem ITEM_LUCKY_EGG
# 1110 "data/maps/daycarebase/scripts.pory"
	waitmessage
# 1111 "data/maps/daycarebase/scripts.pory"
	setflag FLAG_ITEM_DAYCARE_EAST1
# 1112 "data/maps/daycarebase/scripts.pory"
	release
	end


# 13 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_0:
# 13 "data/maps/daycarebase/scripts.pory"
	walk_right
	step_end

# 15 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_1:
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
# 15 "data/maps/daycarebase/scripts.pory"
	walk_down
	step_end

# 19 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_2:
# 19 "data/maps/daycarebase/scripts.pory"
	face_right
	step_end

# 20 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_3:
# 20 "data/maps/daycarebase/scripts.pory"
	face_left
	step_end

# 27 "data/maps/daycarebase/scripts.pory"
DaycareIntro_Movement_4:
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 27 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
	step_end

# 201 "data/maps/daycarebase/scripts.pory"
MimikyuDialog_Movement_0:
# 201 "data/maps/daycarebase/scripts.pory"
	face_player
	step_end

# 390 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_0:
# 390 "data/maps/daycarebase/scripts.pory"
	face_down
	step_end

# 392 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_1:
# 392 "data/maps/daycarebase/scripts.pory"
	walk_down
# 392 "data/maps/daycarebase/scripts.pory"
	walk_down
	step_end

# 402 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_2:
# 402 "data/maps/daycarebase/scripts.pory"
	walk_right
# 402 "data/maps/daycarebase/scripts.pory"
	walk_right
# 402 "data/maps/daycarebase/scripts.pory"
	walk_right
# 402 "data/maps/daycarebase/scripts.pory"
	walk_right
# 402 "data/maps/daycarebase/scripts.pory"
	walk_right
	step_end

# 408 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_3:
# 408 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 408 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 408 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 408 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
# 408 "data/maps/daycarebase/scripts.pory"
	walk_fast_right
	step_end

# 410 "data/maps/daycarebase/scripts.pory"
DaycareOldManDialog_Movement_4:
# 410 "data/maps/daycarebase/scripts.pory"
	walk_fast_up
	step_end

DaycareIntro_Text_0:
# 9 "data/maps/daycarebase/scripts.pory"
	.string "Daycare Man$"

DaycareIntro_Text_1:
# 10 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pDespite what trainers may see from\nRoute 117, the Daycare is a vast\larea filled with biomes for nearly\levery type of Pokémon!\pExplore the Daycare and interact\nwith many of the Pokémon we are\lraising.\pYou never know what friends you\nwill make along the way!\pNow, I do expect you to be holding\nan Egg at some point... Every Ditto\lI've raised has produced one.\pNow you two, run along and do what\nyou need to do to get that Egg!\pWhen you're holding an Egg,\ncome back and talk to me and\lwe can get it to your trainer.$"

DaycareIntro_Text_2:
# 24 "data/maps/daycarebase/scripts.pory"
	.string "Vaporeon$"

DaycareIntro_Text_3:
# 25 "data/maps/daycarebase/scripts.pory"
	.string "I don't care what the Daycare Man\nsays, I'm not interested in going on\lan Egg hunt.\pJust because Brendan put us in here\ntogether doesn't mean I have to\lhelp you.\pI'm going for a swim.\pYou'll just have to find that Egg\non your own.$"

ShrinkToPikachuCave_Text_0:
# 47 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole that you can\nsqueeze through.\pWould you like to squeeze through it?$"

ShrinkToPikachuCave_Text_1:
# 64 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.\pWould you like to transform into\nCutiefly to squeeze through it?$"

ShrinkToPikachuCave_Text_2:
# 80 "data/maps/daycarebase/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.$"

MimikyuDialog_Text_0:
# 205 "data/maps/daycarebase/scripts.pory"
	.string "Pikachu$"

MimikyuDialog_Text_1:
# 207 "data/maps/daycarebase/scripts.pory"
	.string "Hey!\pI'm just a normal Pikachu in my usual\nspot!$"

MimikyuDialog_Text_2:
# 212 "data/maps/daycarebase/scripts.pory"
	.string "Mimikyu$"

MimikyuDialog_Text_3:
# 214 "data/maps/daycarebase/scripts.pory"
	.string "Oh...\nYou caught me.\pI wish I could disguise myself as\nwell as you can...\pMaybe then people would like me more...$"

MimikyuDialog_Text_4:
# 226 "data/maps/daycarebase/scripts.pory"
	.string "I've always looked up to you\nPikachu.\pI hope my disguise doesn't insult\nyou..$"

MimikyuDialog_Text_5:
# 243 "data/maps/daycarebase/scripts.pory"
	.string "Oh!\nA real life Pikachu!\pYou are my idol.\pPlease take this.\n$"

KecleonDialog_Text_0:
# 270 "data/maps/daycarebase/scripts.pory"
	.string "Kecleon$"

KecleonDialog_Text_1:
# 272 "data/maps/daycarebase/scripts.pory"
	.string "Where do Eggs come from?\pMy trainer left me here a long time\nago and I've yet to find one.\pDo you know?\pI've always heard of Dittos\nholding onto Eggs...$"

KecleonDialog_Text_2:
# 282 "data/maps/daycarebase/scripts.pory"
	.string "Where do Eggs come from?\pMy trainer left me here a long time\nago and I've yet to find one.$"

AzumarillDialog_Text_0:
# 296 "data/maps/daycarebase/scripts.pory"
	.string "Azumarill$"

AzumarillDialog_Text_1:
# 298 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pYou'll fit in well here.$"

AzumarillDialog_Text_2:
# 308 "data/maps/daycarebase/scripts.pory"
	.string "Oh!\nThank goodness you aren't a Ditto...\pMy trainer keeps putting me in here\nwith Dittos hoping we'll find an\lEgg.\pThey gave me this Sea Incense,\nbut I'm not sure how that would\lhelp us on our hunt...$"

DaycareOldManDialog_Text_0:
# 326 "data/maps/daycarebase/scripts.pory"
	.string "Back from exploring the Daycare?\pAh!\nBut where is your Egg?\pKeep doing whatever it is you\nDittos do and come back when\lyou have one!$"

DaycareOldManDialog_Text_1:
# 333 "data/maps/daycarebase/scripts.pory"
	.string "Why, who are you?\pI'm looking for a Ditto.\n$"

DaycareOldManDialog_Text_2:
# 342 "data/maps/daycarebase/scripts.pory"
	.string "Welcome to the Daycare!\pDespite what trainers may see from\nRoute 117, the Daycare is a vast\larea filled with biomes for nearly\levery type of Pokémon!\pExplore the Daycare and interact\nwith many of the Pokémon we are\lraising.\pYou never know what friends you\nwill make along the way!\pNow, I do expect you to be holding\nan Egg at some point... Every Ditto\lI've raised has produced one.\pWhen you're holding an Egg,\ncome back and talk to me and\lwe can get it to your trainer.$"

DaycareOldManDialog_Text_3:
# 360 "data/maps/daycarebase/scripts.pory"
	.string "Why what do we have here?\nGoodness!\pYou're holding an Egg!\pWherever did you get this?\pIt's the darndest thing.\pYou Pokémon always seem to find\nthese Eggs, but I can never figure\lout where they come from.\pWould you like to give me the Egg\nso that I may give it to your\lTrainer?$"

DaycareOldManDialog_Text_4:
# 366 "data/maps/daycarebase/scripts.pory"
	.string "Ditto handed over the Egg.\n$"

DaycareOldManDialog_Text_5:
# 370 "data/maps/daycarebase/scripts.pory"
	.string "Thank you for the Egg!\pAs a reward, take this EXP!\n$"

DaycareOldManDialog_Text_6:
# 383 "data/maps/daycarebase/scripts.pory"
	.string "Ditto grew to level {STR_VAR_1}.\n$"

DaycareOldManDialog_Text_7:
# 388 "data/maps/daycarebase/scripts.pory"
	.string "With this Egg, I can now fulfill\nmy duties.$"

DaycareOldManDialog_Text_8:
# 413 "data/maps/daycarebase/scripts.pory"
	.string "Ah, it's you!\pWe were raising your Pokémon\nand my goodness, were we surprised!\pYour Pokémon had an Egg!\pWe don't know how it got there,\nbut your Pokémon had it.\pYou do want it, yes?\n$"

DaycareOldManDialog_Text_9:
# 426 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0\n{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Lucky Eggs found: {COLOR BLUE}{SHADOW LIGHT_BLUE}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts\nand found all of the Lucky Eggs!\pCongratulations!$"

DaycareOldManDialog_Text_10:
# 440 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts!\pKeep searching for the remaining\nLucky Eggs and defeat Mew again to\l100% the game!$"

DaycareOldManDialog_Text_11:
# 446 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR BLUE}{SHADOW LIGHT_BLUE}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pAmazing!\pYou beat the game with 0 whiteouts!\pKeep searching for the remaining\nLucky Eggs and defeat Mew again to\l100% the game!$"

DaycareOldManDialog_Text_12:
# 452 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}0{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat job!\pYou can continue this save and\nfind the remaining Lucky eggs.\pChallenge Mew again and speak\nto the Daycare Man.\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_13:
# 458 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR BLUE}{SHADOW LIGHT_BLUE}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat Job!\nYou found all of the Lucky Eggs!\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_14:
# 464 "data/maps/daycarebase/scripts.pory"
	.string "Pokémon Transform Stats:\pNumber of Whiteouts: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_1}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\nLucky Eggs found: {COLOR RED}{SHADOW LIGHT_RED}{STR_VAR_2}{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}/18\pGreat job!\pYou can continue this save and\nfind the remaining Lucky eggs.\pChallenge Mew again and speak\nto the Daycare Man.\pStart a new run to try to win\nwithout whiting out.$"

DaycareOldManDialog_Text_15:
# 477 "data/maps/daycarebase/scripts.pory"
	.string "The Daycare Man ripped the Egg\nfrom Ditto's clutches.$"

VaporeonDialog_Text_0:
# 608 "data/maps/daycarebase/scripts.pory"
	.string "Ugh!\nYou again.\pEveryone here keeps asking me to\nhelp them search for Eggs.\pCan't a Vaporeon just relax?$"

VaporeonDialog_Text_1:
# 618 "data/maps/daycarebase/scripts.pory"
	.string "Ugh!\nYou again...$"

VaporeonDialog_Text_2:
# 624 "data/maps/daycarebase/scripts.pory"
	.string "Wait you found an Egg?!\pHuh. I always thought you needed two\nPokémon to find an Egg...\pWhat will hatch from it since you found\nit by yourself?$"

LaprasDialog_Text_0:
# 634 "data/maps/daycarebase/scripts.pory"
	.string "Lapras$"

LaprasDialog_Text_1:
# 636 "data/maps/daycarebase/scripts.pory"
	.string "I love the Daycare!\pIt's so peaceful and quiet here.\pI can just float around all day\nand relax.\pThose waterfalls are pretty\nvicious, I won't go near them.\pI've heard that Dragonair can\neasily scale even the largest\lof waterfalls!$"

LinooneDialog_Text_0:
# 648 "data/maps/daycarebase/scripts.pory"
	.string "Linoone$"

LinooneDialog_Text_1:
# 650 "data/maps/daycarebase/scripts.pory"
	.string "The Daycare is huge!\pIt's a bit scary to explore,\nso I stay up here.\pRiolu is way more brave than I\nam and has explored the entirety\lof the Daycare.\pYou should talk with Riolu if\nyou get lost!\pI'm sure they can help!\n$"

LinooneDialog_Text_2:
# 662 "data/maps/daycarebase/scripts.pory"
	.string "Those Dittos really freak me out.\pThey could be any one of us right\nnow...\pEven you!... or me!\n$"

BulbsaurDialog_Text_0:
# 673 "data/maps/daycarebase/scripts.pory"
	.string "Bulbasaur$"

BulbsaurDialog_Text_1:
# 675 "data/maps/daycarebase/scripts.pory"
	.string "You want to know where Eggs\ncome from?\pI heard that a Pokémon needs\nto go on a great adventure to\lmeet a shapeshifting Pokémon.\pIf you can best them, they will\ngive you an egg!\pAt least, that's what Venusaur\ntold me...$"

CombeeDialog_Text_0:
# 685 "data/maps/daycarebase/scripts.pory"
	.string "Combee$"

CombeeDialog_Text_1:
# 687 "data/maps/daycarebase/scripts.pory"
	.string "I've been in this Daycare\nfor ages!\pI've flown all around and\npollenated so many flowers\lbut I still haven't gained a\lsingle level.\pI'm beginning to believe gaining\nEXP here is nothing more\lthan a big ole myth!$"

Porygon2Dialog_Text_0:
# 697 "data/maps/daycarebase/scripts.pory"
	.string "Porygon2$"

Porygon2Dialog_Text_1:
# 699 "data/maps/daycarebase/scripts.pory"
	.string "Another Ditto...\pI'm actually a Ditto too,\nI just prefer this look.\pThe Daycare population must be at\nleast 75 percent Dittos!\pMost Dittos will take on different\nforms.\pYou won't be able to transform\ninto a form that another Ditto has\ltaken on though.$"

ScytherDialog_Text_0:
# 711 "data/maps/daycarebase/scripts.pory"
	.string "Scyther$"

ScytherDialog_Text_1:
# 713 "data/maps/daycarebase/scripts.pory"
	.string "One in every {COLOR BLUE}{SHADOW LIGHT_BLUE}fifty {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Dittos that I\nsee here are blue.$"

ScytherDialog_Text_2:
# 718 "data/maps/daycarebase/scripts.pory"
	.string "Oh hey!\pYou're one of the blue ones!\pYou must've gotten really lucky!$"

ScytherDialog_Text_3:
# 727 "data/maps/daycarebase/scripts.pory"
	.string "One in every {COLOR BLUE}{SHADOW LIGHT_BLUE}fifty {COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Dittos that I\nsee here are blue.\pThere must be some reason trainers\nput so many in here...$"

RioluDialog_Text_0:
# 742 "data/maps/daycarebase/scripts.pory"
	.string "Riolu$"

RioluDialog_Text_1:
# 744 "data/maps/daycarebase/scripts.pory"
	.string "Back with a Lucky Egg?\n$"

RioluDialog_Text_2:
# 750 "data/maps/daycarebase/scripts.pory"
	.string "Great!\pI can tell about the habitat and\nability of a Pokémon in the Daycare.$"

RioluDialog_Text_3:
# 752 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to exchange a\nLucky Egg?$"

RioluDialog_Text_4:
# 756 "data/maps/daycarebase/scripts.pory"
	.string "Which Pokémon would you like to\nknow more about?$"

RioluDialog_Text_5:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Arcanine$"

RioluDialog_Text_6:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Chinchou$"

RioluDialog_Text_7:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Cutiefly$"

RioluDialog_Text_8:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Dragonair$"

RioluDialog_Text_9:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Marill$"

RioluDialog_Text_10:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Machamp$"

RioluDialog_Text_11:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Noivern$"

RioluDialog_Text_12:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Rhyhorn$"

RioluDialog_Text_13:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Lurantis$"

RioluDialog_Text_14:
# 758 "data/maps/daycarebase/scripts.pory"
	.string "Weavile$"

RioluDialog_Text_15:
# 761 "data/maps/daycarebase/scripts.pory"
	.string "Arcanine can be found deep in the\nVolcano.\pIt can run really fast and scale\nhills that would normally be too\lslippery to climb!$"

RioluDialog_Text_16:
# 769 "data/maps/daycarebase/scripts.pory"
	.string "Chinchou can be found in a cave\non the water in the desert.\pIt can dive deep underwater.\n$"

RioluDialog_Text_17:
# 777 "data/maps/daycarebase/scripts.pory"
	.string "Cutiefly can be found in the\nDaycare's flowers to the west.\pIt's a tiny Pokémon that can\nfit through small openings.$"

RioluDialog_Text_18:
# 785 "data/maps/daycarebase/scripts.pory"
	.string "Dragonair can be found at the lake.\pIt can be a bit cryptic so it\nmay be difficult to reach.\pIt can scale large waterfalls\nwith ease.$"

RioluDialog_Text_19:
# 793 "data/maps/daycarebase/scripts.pory"
	.string "Marill can be found at the lake,\nusually by the shore.\pIt's a bit shy so it may be hiding.\pIt can float in any body of water.\n$"

RioluDialog_Text_20:
# 801 "data/maps/daycarebase/scripts.pory"
	.string "Machamp likes to train deep in\nthe mountains.\pIt is a very tough and solitary\nPokémon.\pIts strength can move large\nboulders.$"

RioluDialog_Text_21:
# 809 "data/maps/daycarebase/scripts.pory"
	.string "Noivern hangs out in a dark\ncave above the Daycare Falls.\pIt's quite a powerful Pokémon,\nso be prepared for a fight.\pIt can soar through the air,\nreaching places unreachable by\lnon_flying types.$"

RioluDialog_Text_22:
# 817 "data/maps/daycarebase/scripts.pory"
	.string "Pikachu is standing on that cliff\nright over there.\pIts electricity can light up even\nthe darkest of caves.$"

RioluDialog_Text_23:
# 825 "data/maps/daycarebase/scripts.pory"
	.string "Rhyhorn lives in the desert.\pIt's quite a friendly Pokémon,\nbut don't upset it!\pIt is strong enough to smash\nsolid rocks!$"

RioluDialog_Text_24:
# 833 "data/maps/daycarebase/scripts.pory"
	.string "Lurantis has been spending time\nacross the water in the mountains.\pIts sharp limbs can cut through\nsmall trees.$"

RioluDialog_Text_25:
# 841 "data/maps/daycarebase/scripts.pory"
	.string "Weavile is quite the ninja.\pIt spends time in the tall trees\nin the jungle.\pIt demands a fierce challenger\nto battle it.\pIts agility allows it to cross\neven the smallest of walkways.$"

RioluDialog_Text_26:
# 851 "data/maps/daycarebase/scripts.pory"
	.string "Oh.\pWhat else are you gonna do\nwith that egg?$"

RioluDialog_Text_27:
# 863 "data/maps/daycarebase/scripts.pory"
	.string "No?\nCome back when you do!$"

RioluDialog_Text_28:
# 875 "data/maps/daycarebase/scripts.pory"
	.string "Hiya!\pI'm Riolu!\pI've visited every biome the\nDaycare has to offer.\lI know it like the back of my paw!\pIf you need guidance on where a\ncertain Pokémon might be,\lI'm your Pokémon!\pAlthough I won't do it for free...\pBring me Lucky Eggs, and I'll tell\nyou what I know.$"

BattleVsPikachu_Text_0:
# 894 "data/maps/daycarebase/scripts.pory"
	.string "You really lit me up.\pBest of luck on your journey!\n$"

BattleVsPikachu_Text_1:
# 909 "data/maps/daycarebase/scripts.pory"
	.string "A Ditto!\pYou must be on your quest to obtain\nyour egg.\pDefeat me in battle and I'll allow\nyou to transform into me!$"

BattleVsPikachu_Text_2:
# 928 "data/maps/daycarebase/scripts.pory"
	.string "You have gained the ability to\ntransform into Pikachu!$"

BattleVsPikachu_Text_3:
# 936 "data/maps/daycarebase/scripts.pory"
	.string "How electrifying!\pElectric_type moves are powerful\nagainst Water_type Pokémon.\pThey typically spend their time in\nthe Lake Biome here.\pYou can hop right down off the cliff\nhere to get there faster!$"

ChanseyHeal_Text_0:
# 950 "data/maps/daycarebase/scripts.pory"
	.string "Chansey$"

ChanseyHeal_Text_1:
# 952 "data/maps/daycarebase/scripts.pory"
	.string "Hello there!\pI can heal you in exchange for\na Lucky Egg.$"

ChanseyHeal_Text_2:
# 954 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to heal?$"

ChanseyHeal_Text_3:
# 968 "data/maps/daycarebase/scripts.pory"
	.string "You have been restored to full health!$"

ChanseyHeal_Text_4:
# 977 "data/maps/daycarebase/scripts.pory"
	.string "You don't have a Lucky Egg!\pCome back when you do.$"

ChanseyHeal_Text_5:
# 987 "data/maps/daycarebase/scripts.pory"
	.string "Oh, okay then.$"

ChanseyHeal_Text_6:
# 1000 "data/maps/daycarebase/scripts.pory"
	.string "You look new!\pHave you found any Lucky Eggs yet?\pThey aren't quite the Mythical Egg\nyou are in search of, but many\lPokémon around the daycare will\loffer trades or services for them!\pDon't be afraid to use them!\pI'll offer to bring you back to\nfull health for just one!$"

DaycareBase_Ditto_Text_0:
# 1017 "data/maps/daycarebase/scripts.pory"
	.string "Would you like to change out your\ntransformation options?$"

DaycareBase_Ditto_Text_1:
# 1029 "data/maps/daycarebase/scripts.pory"
	.string "Ditto$"

DaycareBase_Ditto_Text_2:
# 1031 "data/maps/daycarebase/scripts.pory"
	.string "Come back anytime!$"

DaycareBase_Ditto_Text_3:
# 1043 "data/maps/daycarebase/scripts.pory"
	.string "Ditto!\pYou can transform into any\nPokémon you defeat in battle!\pThis only applies to Pokémon\nnot already using Transform...\lLike other Dittos in disguise.\pPress the{SELECT_BUTTON} button to\naccess your transformation menu.\pYou can also view more information\nabout your transformations from\lthe Xforms option on the {START_BUTTON} menu.\pTo swap out your transformation\noptions, press the {L_BUTTON} button!$"

DaycareBase_Ditto_Text_4:
# 1055 "data/maps/daycarebase/scripts.pory"
	.string "Hello there fellow Ditto!\pDaycare Man asked you to get an Egg\nfor him, did he?\pWell, you're about to learn the\nsecret of how we Dittos are\lalways found holding Eggs.\pIt'll be quite the adventure!\pTalk to any of the Dittos around\nthe Daycare for some control tips,\lincluding me!$"
