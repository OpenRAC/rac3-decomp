/* Near miss of func_003A0F98 with its file's own flags: tools/check.py reports 29 diff
   (the version it replaces: 33).
*/

/* PAL candidate for func_003A0F98.
   The retail build reaches D_001D5B90, D_001D5B94 and D_001D9FD0 through
   lui/lw (absolute), not through $gp, so they are used as arrays of unknown
   size here (the file already declares them that way); the four small
   counters stay scalars, which is what puts them in $gp. */

__asm__(".extern D_001D6DA4_003A0F98, 4");
__asm__(".extern D_001D6D9C_003A0F98, 4");
__asm__(".extern D_001D6DA0_003A0F98, 4");
__asm__(".extern D_001D6DA8_003A0F98, 4");
extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001A7430_003A0F98[];
extern s32 D_001D9FD0[];
extern s32 D_001D6DA4_003A0F98;
extern s32 D_001D6D9C_003A0F98;
extern s32 D_001D6DA0_003A0F98;
extern s32 D_001D6DA8_003A0F98;
s32 func_003A0F98(s32 screenId, s32 arg1) {
    s32 result;
    if (*(s32 *)D_001D5B90 != -2) result = 1; else result = 0;
    if (D_001D6DA4_003A0F98 == 0) result = 1;
    if (*(s32 *)D_001D5B94 != 4) {
        if (D_001A7430_003A0F98[0] == 0) result = -1;
    }
    if (result == 0) {
        s32 i = D_001D6DA4_003A0F98 - 1;
        D_001D6D9C_003A0F98 = screenId;
        D_001D6DA0_003A0F98 = arg1;
        D_001D6DA4_003A0F98 = i;
        *(s32 *)D_001D5B90 = D_001D9FD0[i];
        D_001D6DA8_003A0F98 = 0;
    }
    return result;
}
