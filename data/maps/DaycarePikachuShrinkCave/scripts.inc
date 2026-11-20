DaycarePikachuShrinkCave_MapScripts::
# 2 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 2 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
	return


TarountulaDialog::
# 6 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lockall
# 7 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	faceplayer
# 8 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq TarountulaDialog_1
# 18 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_DITTO
	goto_if_eq TarountulaDialog_2
# 41 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername TarountulaDialog_Text_0
# 42 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_NORMAL
# 43 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_2, MSGBOX_DEFAULT
# 44 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 45 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 46 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_HAPPY
# 47 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	playse SE_PIN
# 48 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement tarountula, Common_Movement_ExclamationMark
# 49 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement tarountula
# 50 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_5, MSGBOX_DEFAULT
# 51 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 52 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 53 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_NORMAL
# 54 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_6, MSGBOX_AUTOCLOSE
# 55 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 56 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 57 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

TarountulaDialog_1:
# 10 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername TarountulaDialog_Text_0
# 11 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_NORMAL
# 12 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_1, MSGBOX_AUTOCLOSE
# 13 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 14 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 15 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

TarountulaDialog_2:
# 20 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername TarountulaDialog_Text_0
# 21 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_NORMAL
# 22 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_2, MSGBOX_DEFAULT
# 23 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 24 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 25 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_HAPPY
# 26 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	playse SE_PIN
# 27 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement tarountula, Common_Movement_ExclamationMark
# 28 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement tarountula
# 29 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_3, MSGBOX_DEFAULT
# 30 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 31 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 32 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_TAROUNTULA, EMOTE_NORMAL
# 33 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox TarountulaDialog_Text_4, MSGBOX_AUTOCLOSE
# 34 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 35 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 36 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


ShroodleInCave::
# 64 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 65 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	faceplayer
# 66 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_set FLAG_SHROODLE_BATTLE, ShroodleInCave_1
# 78 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Shroodle, ShroodleInCave_Movement_0
# 79 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Shroodle
# 80 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 81 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Shroodle, Common_Movement_ExclamationMark
# 82 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Shroodle
# 83 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 84 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 85 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 86 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_2, MSGBOX_AUTOCLOSE
# 87 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 88 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SHROODLE, 25
# 89 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 90 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 91 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ShroodleInCave_4
	return

ShroodleInCave_1:
# 68 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 69 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 70 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_1, MSGBOX_DEFAULT
# 71 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 72 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 73 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShroodleInCave_4:
# 93 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 94 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 95 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_1, MSGBOX_DEFAULT
# 96 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SHROODLE_BATTLE
# 97 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 98 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 99 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


ShroodleInCaveTrigger::
# 107 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_unset FLAG_SHROODLE_BATTLE, ShroodleInCaveTrigger_1
	return

ShroodleInCaveTrigger_1:
# 109 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 110 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Shroodle, Common_Movement_ExclamationMark
# 111 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Shroodle
# 112 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 113 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 114 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	switch VAR_TEMP_2
# 116 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 33, ShroodleInCaveTrigger_4
# 138 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 32, ShroodleInCaveTrigger_5
	return

ShroodleInCaveTrigger_4:
# 117 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 118 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Shroodle, ShroodleInCaveTrigger_Movement_0
# 119 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Shroodle
# 120 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 121 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 122 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_2, MSGBOX_AUTOCLOSE
# 123 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 124 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SHROODLE, 25
# 125 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 126 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 127 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ShroodleInCaveTrigger_6
	return

ShroodleInCaveTrigger_5:
# 139 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 140 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 141 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 142 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_2, MSGBOX_AUTOCLOSE
# 143 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 144 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SHROODLE, 25
# 145 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 146 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 147 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ShroodleInCaveTrigger_8
	return

ShroodleInCaveTrigger_6:
# 129 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 130 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 131 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_1, MSGBOX_DEFAULT
# 132 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SHROODLE_BATTLE
# 133 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 134 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 135 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShroodleInCaveTrigger_8:
# 149 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername ShroodleInCave_Text_0
# 150 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SHROODLE, EMOTE_HAPPY
# 151 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShroodleInCave_Text_1, MSGBOX_DEFAULT
# 152 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SHROODLE_BATTLE
# 153 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 154 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 155 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


SewaddleInCave::
# 164 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 165 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	faceplayer
# 166 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_set FLAG_SEWADDLE_BATTLE, SewaddleInCave_1
# 178 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Sewaddle, ShroodleInCave_Movement_0
# 179 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Sewaddle
# 180 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 181 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Sewaddle, Common_Movement_ExclamationMark
# 182 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Sewaddle
# 183 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 184 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 185 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 186 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_2, MSGBOX_AUTOCLOSE
# 187 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 188 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SEWADDLE, 25
# 189 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 190 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 191 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SewaddleInCave_4
	return

SewaddleInCave_1:
# 168 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 169 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 170 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_1, MSGBOX_DEFAULT
# 171 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 172 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 173 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

SewaddleInCave_4:
# 193 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 194 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 195 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_3, MSGBOX_DEFAULT
# 196 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SEWADDLE_BATTLE
# 197 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 198 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 199 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


SewaddleInCaveTrigger::
# 207 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_unset FLAG_SEWADDLE_BATTLE, SewaddleInCaveTrigger_1
	return

SewaddleInCaveTrigger_1:
# 209 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 210 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Sewaddle, Common_Movement_ExclamationMark
# 211 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Sewaddle
# 212 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 213 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 214 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	switch VAR_TEMP_1
# 216 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 5, SewaddleInCaveTrigger_4
# 237 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 6, SewaddleInCaveTrigger_5
	return

SewaddleInCaveTrigger_4:
# 217 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, SewaddleInCaveTrigger_Movement_0
# 218 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Sewaddle
# 219 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 220 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 221 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_2, MSGBOX_AUTOCLOSE
# 222 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 223 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SEWADDLE, 25
# 224 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 225 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 226 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SewaddleInCaveTrigger_6
	return

SewaddleInCaveTrigger_5:
# 238 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, SewaddleInCaveTrigger_Movement_0
# 239 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Sewaddle, SewaddleInCaveTrigger_Movement_1
# 240 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Sewaddle
# 241 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 242 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 243 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_2, MSGBOX_AUTOCLOSE
# 244 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 245 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_SEWADDLE, 25
# 246 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 247 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 248 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SewaddleInCaveTrigger_8
	return

SewaddleInCaveTrigger_6:
# 228 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 229 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 230 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_3, MSGBOX_DEFAULT
# 231 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SEWADDLE_BATTLE
# 232 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 233 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 234 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

SewaddleInCaveTrigger_8:
# 250 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SewaddleInCave_Text_0
# 251 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SEWADDLE, EMOTE_NORMAL
# 252 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SewaddleInCave_Text_3, MSGBOX_DEFAULT
# 253 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_SEWADDLE_BATTLE
# 254 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 255 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 256 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


BlipbugInCave::
# 264 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 265 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	faceplayer
# 266 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_set FLAG_BLIPBUG_BATTLE, BlipbugInCave_1
# 278 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, ShroodleInCave_Movement_0
# 279 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Blipbug
# 280 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 281 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, Common_Movement_ExclamationMark
# 282 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Blipbug
# 283 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 284 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 285 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 286 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_2, MSGBOX_AUTOCLOSE
# 287 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 288 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_BLIPBUG, 25
# 289 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 290 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 291 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BlipbugInCave_4
	return

BlipbugInCave_1:
# 268 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 269 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 270 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_1, MSGBOX_DEFAULT
# 271 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 272 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 273 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

BlipbugInCave_4:
# 293 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 294 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 295 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_3, MSGBOX_DEFAULT
# 296 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_BLIPBUG_BATTLE
# 297 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 298 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 299 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


BlipbugInCaveTrigger::
# 307 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_unset FLAG_BLIPBUG_BATTLE, BlipbugInCaveTrigger_1
	return

BlipbugInCaveTrigger_1:
# 309 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	special PlayTrainerEncounterMusic
# 310 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, Common_Movement_ExclamationMark
# 311 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement
# 312 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 60
# 313 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
# 314 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	switch VAR_TEMP_2
# 316 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 13, BlipbugInCaveTrigger_4
# 338 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 12, BlipbugInCaveTrigger_5
# 360 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 11, BlipbugInCaveTrigger_6
# 382 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	case 10, BlipbugInCaveTrigger_7
	return

BlipbugInCaveTrigger_4:
# 317 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 318 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, BlipbugInCaveTrigger_Movement_0
# 319 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Blipbug
# 320 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 321 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 322 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_2, MSGBOX_AUTOCLOSE
# 323 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 324 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_BLIPBUG, 25
# 325 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 326 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 327 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BlipbugInCaveTrigger_8
	return

BlipbugInCaveTrigger_5:
# 339 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 340 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, BlipbugInCaveTrigger_Movement_1
# 341 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Blipbug
# 342 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 343 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 344 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_2, MSGBOX_AUTOCLOSE
# 345 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 346 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_BLIPBUG, 25
# 347 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 348 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 349 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BlipbugInCaveTrigger_10
	return

BlipbugInCaveTrigger_6:
# 361 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 362 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement Blipbug, ShroodleInCaveTrigger_Movement_0
# 363 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement Blipbug
# 364 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 365 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 366 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_2, MSGBOX_AUTOCLOSE
# 367 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 368 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_BLIPBUG, 25
# 369 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 370 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 371 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BlipbugInCaveTrigger_12
	return

BlipbugInCaveTrigger_7:
# 383 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement LOCALID_PLAYER, DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
# 384 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 385 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 386 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_2, MSGBOX_AUTOCLOSE
# 387 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 388 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setwildbattle SPECIES_BLIPBUG, 25
# 389 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dowildbattle
# 390 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 391 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq BlipbugInCaveTrigger_14
	return

BlipbugInCaveTrigger_8:
# 329 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 330 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 331 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_3, MSGBOX_DEFAULT
# 332 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_BLIPBUG_BATTLE
# 333 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 334 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 335 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

BlipbugInCaveTrigger_10:
# 351 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 352 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 353 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_3, MSGBOX_DEFAULT
# 354 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_BLIPBUG_BATTLE
# 355 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 356 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 357 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

BlipbugInCaveTrigger_12:
# 373 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 374 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 375 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_3, MSGBOX_DEFAULT
# 376 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_BLIPBUG_BATTLE
# 377 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 378 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 379 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

BlipbugInCaveTrigger_14:
# 393 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername BlipbugInCave_Text_0
# 394 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_BLIPBUG, EMOTE_NORMAL
# 395 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox BlipbugInCave_Text_3, MSGBOX_DEFAULT
# 396 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	setflag FLAG_BLIPBUG_BATTLE
# 397 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 398 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 399 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


SinisteaDialog::
# 407 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 408 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement sinistea, ShroodleInCave_Movement_0
# 409 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement sinistea
# 410 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq SinisteaDialog_1
# 422 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SinisteaDialog_Text_0
# 423 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SINISTEA, EMOTE_NORMAL
# 424 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	playse SE_PIN
# 425 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement sinistea, Common_Movement_ExclamationMark
# 426 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement sinistea
# 427 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SinisteaDialog_Text_2, MSGBOX_DEFAULT
# 428 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 429 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 430 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

SinisteaDialog_1:
# 412 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername SinisteaDialog_Text_0
# 413 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_SINISTEA, EMOTE_NORMAL
# 414 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox SinisteaDialog_Text_1, MSGBOX_DEFAULT
# 415 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 416 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 417 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


NymbleDialog::
# 436 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 437 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq NymbleDialog_1
# 451 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement nymble, ShroodleInCave_Movement_0
# 452 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement nymble
# 453 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername NymbleDialog_Text_0
# 454 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_NYMBLE, EMOTE_HAPPY
# 455 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	playse SE_PIN
# 456 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement nymble, Common_Movement_ExclamationMark
# 457 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement nymble
# 458 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox NymbleDialog_Text_2, MSGBOX_DEFAULT
# 459 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 460 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 461 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

NymbleDialog_1:
# 439 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	applymovement nymble, ShroodleInCave_Movement_0
# 440 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmovement nymble
# 441 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	speakername NymbleDialog_Text_0
# 442 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	createfieldmugshot MUGSHOT_NYMBLE, EMOTE_NORMAL
# 443 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox NymbleDialog_Text_1, MSGBOX_DEFAULT
# 444 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 445 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	removefieldmugshot
# 446 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end


ShrinkToPikachuCave3::
# 468 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 469 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave3_1
# 483 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave3_4
ShrinkToPikachuCave3_3:
# 512 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_2, MSGBOX_DEFAULT
# 513 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 514 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave3_1:
# 471 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_0, MSGBOX_YESNO
# 472 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave3_8
# 478 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 479 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave3_2:
# 485 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 486 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave3_11
# 504 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_2, MSGBOX_DEFAULT
# 505 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 506 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave3_4:
# 483 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave3_2
	goto ShrinkToPikachuCave3_3

ShrinkToPikachuCave3_8:
# 474 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	warp MAP_DAYCAREBASE, 0
	return

ShrinkToPikachuCave3_11:
# 488 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_1, MSGBOX_YESNO
# 489 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave3_14
# 497 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 498 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave3_14:
# 491 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 492 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 30
# 493 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	warp MAP_DAYCAREBASE, 0
	return


ShrinkToPikachuCave4::
# 521 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	lock
# 522 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave4_1
# 536 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave4_4
ShrinkToPikachuCave4_3:
# 565 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_2, MSGBOX_DEFAULT
# 566 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 567 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave4_1:
# 524 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_0, MSGBOX_YESNO
# 525 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave4_8
# 531 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 532 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave4_2:
# 538 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 539 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave4_11
# 557 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_2, MSGBOX_DEFAULT
# 558 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 559 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave4_4:
# 536 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave4_2
	goto ShrinkToPikachuCave4_3

ShrinkToPikachuCave4_8:
# 527 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	warp MAP_DAYCAREBASE, 1
	return

ShrinkToPikachuCave4_11:
# 541 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	msgbox ShrinkToPikachuCave3_Text_1, MSGBOX_YESNO
# 542 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave4_14
# 550 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	waitmessage
# 551 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	release
	end

ShrinkToPikachuCave4_14:
# 544 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 545 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	delay 30
# 546 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	warp MAP_DAYCAREBASE, 1
	return


# 2 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
DaycarePikachuShrinkCave_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0:
# 2 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	face_up
	step_end

# 78 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
ShroodleInCave_Movement_0:
# 78 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	face_player
	step_end

# 118 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
ShroodleInCaveTrigger_Movement_0:
# 118 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
	step_end

# 217 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
SewaddleInCaveTrigger_Movement_0:
# 217 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	face_left
	step_end

# 239 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
SewaddleInCaveTrigger_Movement_1:
# 239 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_right
	step_end

# 318 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
BlipbugInCaveTrigger_Movement_0:
# 318 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
# 318 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
# 318 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
	step_end

# 340 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
BlipbugInCaveTrigger_Movement_1:
# 340 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
# 340 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	walk_down
	step_end

TarountulaDialog_Text_0:
# 10 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Tarountula$"

TarountulaDialog_Text_1:
# 12 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "This cave feels so much bigger\nfor us small bug types.\pI'm sure bigger Pokémon suspect\nnothing is in here!$"

TarountulaDialog_Text_2:
# 22 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "This cave feels so much bigger\nfor us small bug types.$"

TarountulaDialog_Text_3:
# 29 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "WAIT... HEY!$"

TarountulaDialog_Text_4:
# 33 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "I guess a Ditto could use\nTransform...$"

TarountulaDialog_Text_5:
# 50 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "WAIT... HEY!\pHow did you fit in the tiny\nentrance?$"

TarountulaDialog_Text_6:
# 54 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "OH!\nA Ditto you say...$"

ShroodleInCave_Text_0:
# 68 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Shroodle$"

ShroodleInCave_Text_1:
# 70 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Some say battling is the way to\ngain EXP in the Daycare.\pI've yet to gain a single level...$"

ShroodleInCave_Text_2:
# 86 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "A trespasser!\n$"

SewaddleInCave_Text_0:
# 168 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Sewaddle$"

SewaddleInCave_Text_1:
# 170 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Now that I think about it,\nI haven't gained any EXP...\leven when I've won.$"

SewaddleInCave_Text_2:
# 186 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "I hope I level up after this\nbattle!$"

SewaddleInCave_Text_3:
# 195 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "I won't gain any EXP if I keep\nlosing...$"

BlipbugInCave_Text_0:
# 268 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Blipbug$"

BlipbugInCave_Text_1:
# 270 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "It's best to pick your battles\nhere.\pIt's every Pokémon for\nthemselves, so try to only battle\lPokémon that you have a type\ladvantage over.$"

BlipbugInCave_Text_2:
# 286 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Us little guys need to keep each\nother sharp!$"

BlipbugInCave_Text_3:
# 295 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "You just knew the perfect matchup.\n$"

SinisteaDialog_Text_0:
# 412 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Sinistea$"

SinisteaDialog_Text_1:
# 414 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "In this cave, you'll find only the\nsmallest of Pokémon.\pWe're the only ones who can fit\nthrough that tiny little entrance!$"

SinisteaDialog_Text_2:
# 427 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Hey!\pAren't you a little too big to be\nin here?$"

NymbleDialog_Text_0:
# 441 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Nymble$"

NymbleDialog_Text_1:
# 443 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Our cave is quite barebones when it\ncomes to decor...\pSome Pokémon will make themselves\nright at home when they find space.$"

NymbleDialog_Text_2:
# 458 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "Whoa... you're HUGE!\pPlease don't step on me.\n$"

ShrinkToPikachuCave3_Text_0:
# 471 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "There is a tiny hole that you can\nsqueeze through.\pWould you like to squeeze through it?$"

ShrinkToPikachuCave3_Text_1:
# 488 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.\pWould you like to transform into\nCutiefly to squeeze through it?$"

ShrinkToPikachuCave3_Text_2:
# 504 "data/maps/DaycarePikachuShrinkCave/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.$"
