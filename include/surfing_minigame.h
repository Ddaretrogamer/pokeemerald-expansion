#ifndef GUARD_SURFING_MINIGAME_H
#define GUARD_SURFING_MINIGAME_H

// Script special. returns score in VAR_RESULT, completion status in VAR_0x8005,
// personal best in VAR_0x8006. Resumes the calling script on exit.
void StartSurfingMinigame(void);
void ResetSurfingMinigameRecord(void);

#endif // GUARD_SURFING_MINIGAME_H
