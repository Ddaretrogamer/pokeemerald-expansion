DaycareMausholdShrink_MapScripts::
# 2 "data/maps/DaycareMausholdShrink/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DaycareMausholdShrink_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DaycareMausholdShrink_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 2 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement LOCALID_PLAYER, DaycareMausholdShrink_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0
	return


FamilyofFour::
# 6 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 7 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 8 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_FOUR, FamilyofFour_1
# 105 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 106 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD4, EMOTE_NORMAL
# 107 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_9, MSGBOX_DEFAULT
# 108 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 109 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 110 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_1:
# 10 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 11 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD4, EMOTE_NORMAL
# 12 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_1, MSGBOX_DEFAULT
# 13 "data/maps/DaycareMausholdShrink/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, FamilyofFour_Text_2, FamilyofFour_Text_3, FamilyofFour_Text_4
# 14 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FamilyofFour_5
# 72 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FamilyofFour_8
# 87 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FamilyofFour_13
	return

FamilyofFour_5:
# 16 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAMTHREE_WRONG, FamilyofFour_11
# 51 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 52 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 53 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 54 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 55 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_0
# 56 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 57 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_6, MSGBOX_DEFAULT
# 58 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 59 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_1
# 60 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 61 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_7, MSGBOX_DEFAULT
# 62 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 63 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 64 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 65 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 66 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 4
# 67 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 68 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 69 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_8:
# 74 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 75 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 76 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 77 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 78 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 79 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 80 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 81 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMFOUR_WRONG
# 82 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 83 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 84 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_11:
# 18 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_FAM_THREE, FamilyofFour_16
# 30 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 31 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 32 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 33 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 34 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_0
# 35 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 36 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_6, MSGBOX_DEFAULT
# 37 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 38 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, FamilyofFour_Movement_1
# 39 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 40 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_7, MSGBOX_DEFAULT
# 41 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 42 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 43 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 44 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 45 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 4
# 46 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 47 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 48 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_13:
# 89 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 90 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 91 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 92 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 93 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 94 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 95 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 96 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMFOUR_WRONG
# 97 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 98 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 99 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofFour_16:
# 20 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 21 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 22 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold4, Common_Movement_ExclamationMark
# 23 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold4
# 24 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_5, MSGBOX_DEFAULT
# 25 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_FOUR
# 26 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 27 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


FamilyofThree::
# 116 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 117 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 118 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_THREE, FamilyofThree_1
# 215 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 216 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD3, EMOTE_NORMAL
# 217 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_2, MSGBOX_DEFAULT
# 218 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 219 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 220 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_1:
# 120 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 121 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_MAUSHOLD3, EMOTE_NORMAL
# 122 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_1, MSGBOX_DEFAULT
# 123 "data/maps/DaycareMausholdShrink/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, FamilyofFour_Text_2, FamilyofFour_Text_3, FamilyofFour_Text_4
# 124 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FamilyofThree_5
# 139 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq FamilyofThree_8
# 197 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FamilyofThree_10
	return

FamilyofThree_5:
# 126 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 127 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 128 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 129 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 130 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 131 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 132 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 133 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMTHREE_WRONG
# 134 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 135 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 136 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_8:
# 141 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_FAM_FOUR, FamilyofThree_13
# 176 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 177 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 178 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 179 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 180 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofThree_Movement_0
# 181 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 182 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_0, MSGBOX_DEFAULT
# 183 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 184 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofFour_Movement_1
# 185 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 186 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_1, MSGBOX_DEFAULT
# 187 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 188 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 189 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 190 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 191 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 3
# 192 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 193 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 194 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_10:
# 199 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 200 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 201 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 202 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 203 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_8, MSGBOX_DEFAULT
# 204 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 205 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 206 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAMTHREE_WRONG
# 207 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 208 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 209 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_13:
# 143 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAMFOUR_WRONG, FamilyofThree_16
# 155 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 156 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 157 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 158 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 159 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofThree_Movement_0
# 160 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 161 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_0, MSGBOX_DEFAULT
# 162 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 163 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, FamilyofFour_Movement_1
# 164 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement
# 165 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofThree_Text_1, MSGBOX_DEFAULT
# 166 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 167 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 168 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 169 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 170 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_POTION, 3
# 171 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 172 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 173 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

FamilyofThree_16:
# 145 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername FamilyofFour_Text_0
# 146 "data/maps/DaycareMausholdShrink/scripts.pory"
	playse SE_PIN
# 147 "data/maps/DaycareMausholdShrink/scripts.pory"
	applymovement Maushold3, Common_Movement_ExclamationMark
# 148 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmovement Maushold3
# 149 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox FamilyofFour_Text_5, MSGBOX_DEFAULT
# 150 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_THREE
# 151 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 152 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


Familyoftwo::
# 226 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_unset FLAG_FAM_TWO, Familyoftwo_1
# 243 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 244 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 245 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername Familyoftwo_Text_0
# 246 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_TANDEMAUS, EMOTE_NORMAL
# 247 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox Familyoftwo_Text_2, MSGBOX_DEFAULT
# 248 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 249 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 250 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

Familyoftwo_1:
# 228 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 229 "data/maps/DaycareMausholdShrink/scripts.pory"
	faceplayer
# 230 "data/maps/DaycareMausholdShrink/scripts.pory"
	speakername Familyoftwo_Text_0
# 231 "data/maps/DaycareMausholdShrink/scripts.pory"
	createfieldmugshot MUGSHOT_TANDEMAUS, EMOTE_NORMAL
# 232 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox Familyoftwo_Text_1, MSGBOX_DEFAULT
# 233 "data/maps/DaycareMausholdShrink/scripts.pory"
	removefieldmugshot
# 234 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_SUPPRESS_SPEAKER_NAME
# 235 "data/maps/DaycareMausholdShrink/scripts.pory"
	setflag FLAG_FAM_TWO
# 236 "data/maps/DaycareMausholdShrink/scripts.pory"
	giveitem ITEM_LUCKY_EGG, 2
# 237 "data/maps/DaycareMausholdShrink/scripts.pory"
	clearflag FLAG_SUPPRESS_SPEAKER_NAME
# 238 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 239 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end


ShrinkToPikachuCave5::
# 256 "data/maps/DaycareMausholdShrink/scripts.pory"
	lock
# 257 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_eq ShrinkToPikachuCave5_1
# 271 "data/maps/DaycareMausholdShrink/scripts.pory"
	goto_if_set FLAG_TRANS_CUTIEFLY, ShrinkToPikachuCave5_4
ShrinkToPikachuCave5_3:
# 300 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_2, MSGBOX_DEFAULT
# 301 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 302 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_1:
# 259 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_0, MSGBOX_YESNO
# 260 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave5_8
# 266 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 267 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_2:
# 273 "data/maps/DaycareMausholdShrink/scripts.pory"
	checkpartymove MOVE_STICKY_WEB
# 274 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne ShrinkToPikachuCave5_11
# 292 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_2, MSGBOX_DEFAULT
# 293 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 294 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_4:
# 271 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_TRANSFORM_MON, SPECIES_CUTIEFLY
	goto_if_ne ShrinkToPikachuCave5_2
	goto ShrinkToPikachuCave5_3

ShrinkToPikachuCave5_8:
# 262 "data/maps/DaycareMausholdShrink/scripts.pory"
	warp MAP_DAYCAREBASE, 2
	return

ShrinkToPikachuCave5_11:
# 276 "data/maps/DaycareMausholdShrink/scripts.pory"
	msgbox ShrinkToPikachuCave5_Text_1, MSGBOX_YESNO
# 277 "data/maps/DaycareMausholdShrink/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq ShrinkToPikachuCave5_14
# 285 "data/maps/DaycareMausholdShrink/scripts.pory"
	waitmessage
# 286 "data/maps/DaycareMausholdShrink/scripts.pory"
	release
	end

ShrinkToPikachuCave5_14:
# 279 "data/maps/DaycareMausholdShrink/scripts.pory"
	dittotransform SPECIES_CUTIEFLY
# 280 "data/maps/DaycareMausholdShrink/scripts.pory"
	delay 30
# 281 "data/maps/DaycareMausholdShrink/scripts.pory"
	warp MAP_DAYCAREBASE, 2
	return


# 2 "data/maps/DaycareMausholdShrink/scripts.pory"
DaycareMausholdShrink_MapScripts_MAP_SCRIPT_ON_TRANSITION_Movement_0:
# 2 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_up
	step_end

# 34 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofFour_Movement_0:
# 34 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_left
	step_end

# 38 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofFour_Movement_1:
# 38 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_player
	step_end

# 159 "data/maps/DaycareMausholdShrink/scripts.pory"
FamilyofThree_Movement_0:
# 159 "data/maps/DaycareMausholdShrink/scripts.pory"
	face_right
	step_end

FamilyofFour_Text_0:
# 10 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Maushold$"

FamilyofFour_Text_1:
# 12 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "You!\pWelcome to our Maushold Haushold!\pWe've put in great work making\nthis haus a home.\pWe're in a bit of a dispute with\nthe neighbors over the proper\lhaushold size...\pWhat would you say the proper\nsize would be?$"

FamilyofFour_Text_2:
# 13 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Four$"

FamilyofFour_Text_3:
# 13 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Three$"

FamilyofFour_Text_4:
# 13 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Two$"

FamilyofFour_Text_5:
# 24 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Don't pander to us!\pWe heard the neighbors yell\nover to us!$"

FamilyofFour_Text_6:
# 36 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Aha!\pSee that!\nFour is the right number.$"

FamilyofFour_Text_7:
# 40 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Here. Take these four items.\n$"

FamilyofFour_Text_8:
# 78 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Hey!\pHow dare you insult my family!\n$"

FamilyofFour_Text_9:
# 107 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Things in fours just make sense!\n$"

FamilyofThree_Text_0:
# 161 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Aha!\pSee that!\nThree is the right number.$"

FamilyofThree_Text_1:
# 165 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Here. Take these three items.\n$"

FamilyofThree_Text_2:
# 217 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Things in threes just make sense!\n$"

Familyoftwo_Text_0:
# 230 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "Tandemaus$"

Familyoftwo_Text_1:
# 232 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "The neighbors at the bottom of\nthe cliff are always feuding...\pWe decided not to have kids\nand we've been perfectly happy\lup here.\pHere. Take these two items.\n$"

Familyoftwo_Text_2:
# 247 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "We've been quite happy up here.\pWe've built a nice life for\nourselves.\pWe even have enough items\nleftover to afford to make\lfrequent trips around the Daycare!$"

ShrinkToPikachuCave5_Text_0:
# 259 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole that you can\nsqueeze through.\pWould you like to squeeze through it?$"

ShrinkToPikachuCave5_Text_1:
# 276 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.\pWould you like to transform into\nCutiefly to squeeze through it?$"

ShrinkToPikachuCave5_Text_2:
# 292 "data/maps/DaycareMausholdShrink/scripts.pory"
	.string "There is a tiny hole.\pA small Pokémon may be able to\nsqueeze through it.$"
