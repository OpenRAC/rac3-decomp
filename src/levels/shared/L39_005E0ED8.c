#include "common.h"

/* localdecomp:start func_L39_005E0ED8 */
extern void func_0038DAB8(float, float);
void func_L39_005E0ED8(char *a0)
{
    func_0038DAB8(*(float *)(a0 + 0xF8), -1.5707964f);
}
/* localdecomp:end func_L39_005E0ED8 */

/* localdecomp:start func_L39_005E0F00 */
__asm__(".extern D_L39_0024C580, 16");
__asm__(".extern D_L39_0024C588, 16");
__asm__(".extern D_L39_0024C590, 16");
__asm__(".extern D_001D8264_sda, 4");
extern s32 D_L39_0024C580[2];
extern f32 D_L39_0024C588[2];
extern long D_L39_0024C590[1];
extern float D_001D8264_sda;
extern long func_0038DBD8(f32, s32, s32);

void func_L39_005E0F00(s32 a0, long a1)
{
    if (D_L39_0024C580[a0] != 0) {
        D_L39_0024C588[a0] += D_001D8264_sda;
        if (D_L39_0024C588[a0] > 1.0f) {
            D_L39_0024C588[a0] = 0.0f;
        }
        D_L39_0024C590[a0] = func_0038DBD8(D_L39_0024C588[a0], 0x80FFFFFF, (s32)a1);
        D_L39_0024C580[a0]--;
    } else {
        D_L39_0024C590[a0] = a1;
    }
}
/* localdecomp:end func_L39_005E0F00 */
