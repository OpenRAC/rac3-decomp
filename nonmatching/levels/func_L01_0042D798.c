/* PAL near miss (Codex wave 7): near miss: 15 words differ with the file's flags.
 * Worker's note: 15 instruction differences; address scheduling and temporary allocation; best log build/codex/w375/func_L01_0042D798.attempt03.log
 */
#include "common.h"
/* localdecomp:start func_L01_0042D798 */
typedef struct {
    s32 count;
    s32 ids[8];
    s32 values[8];
    s32 saved[8];
    s32 other[8];
    s32 tail[8];
} Stack_0042D798;
extern Stack_0042D798 D_L01_0021F5E0;
extern s32 D_L01_001E0000;
extern s32 D_L01_001E000C;
extern s32 D_001D4BB4;
extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern s32 D_L01_00200670[];
extern s32 D_L01_001FD180[];
__asm__(".extern D_L01_001E0000, 16");
__asm__(".extern D_L01_001E000C, 16");
__asm__(".extern D_001D4BB4, 16");
void func_L01_0042D798(void) {
    s32 id, saved, other, n;
    if (D_L01_0021F5E0.count != 0) {
        --D_L01_0021F5E0.count;
        id = D_L01_0021F5E0.ids[D_L01_0021F5E0.count];
        saved = D_L01_0021F5E0.saved[D_L01_0021F5E0.count];
        other = D_L01_0021F5E0.other[D_L01_0021F5E0.count];
        D_L01_0021F5E0.ids[D_L01_0021F5E0.count] = 0;
        n = D_L01_001E0000 - 1;
        D_L01_0021F5E0.values[D_L01_0021F5E0.count] = 0;
        D_L01_0021F5E0.saved[D_L01_0021F5E0.count] = 0;
        D_L01_001FD9F0[n] = -1;
        D_L01_00200670[n] = 0;
        D_L01_001FD180[n] = 0;
        D_L01_001FDBD0[id] = 255;
        D_L01_0021F5E0.other[D_L01_0021F5E0.count] = 0;
        D_L01_001E000C = saved;
        D_001D4BB4 = other;
        D_L01_001E0000 = n;
        D_L01_0021F5E0.tail[D_L01_0021F5E0.count] = 0;
    }
}
/* localdecomp:end func_L01_0042D798 */
