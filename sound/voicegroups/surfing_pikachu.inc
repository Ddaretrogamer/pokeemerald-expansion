voice_group surfing_pikachu
	voice_square_1 60, 0, 0, 3, 0, 3, 0, 0
	voice_square_1 60, 0, 0, 3, 0, 2, 0, 0
	voice_square_1 60, 0, 0, 0, 0, 2, 0, 0
	voice_square_2 60, 0, 3, 0, 4, 0, 0
	voice_square_2 60, 0, 3, 0, 2, 0, 0
	voice_square_2 60, 0, 3, 0, 6, 0, 0
	voice_square_2 60, 0, 2, 0, 6, 0, 0
	voice_square_2 60, 0, 2, 0, 2, 0, 0
	voice_programmable_wave 60, 0, SurfingPikachuWave, 0, 0, 15, 0

	.align 2
SurfingPikachuWave:
	.byte 0x02, 0x46, 0x8a, 0xce, 0xff, 0xfe, 0xed, 0xdc, 0xcb, 0xa9, 0x87, 0x65, 0x44, 0x33, 0x22, 0x11
