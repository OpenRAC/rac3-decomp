/* PAL near miss (haiku-w4): 16 words differ with the file's flags; the if/else arms reload the lui globals in a different order and the D_L01_001DD1E0 table is a lui pair where retail has $gp. Defined through an asm-label alias because the file declares the callback as void(void). */
#include "common.h"
/* localdecomp:start func_L01_003411A8 */
#include "vu0.h"
typedef struct {
    vu0_q vertex[4];
    s32 color[4];
    f32 uv[4][2];
    long mode, texture, alpha, bits;
} Packet_003411A8;
extern f32 D_L01_001E29D8[];
extern f32 D_L01_001DD22C, D_L01_001DD230;
extern s32 D_L01_001DD220;
__asm__(".extern D_L01_001DD22C, 4");
__asm__(".extern D_L01_001DD230, 4");
__asm__(".extern D_L01_001DD220, 4");
__asm__(".extern D_L01_001DD1B4, 4");
__asm__(".extern D_L01_001DD1B8, 4");
__asm__(".extern D_L01_001DD1C0, 4");
extern s32 D_L01_001DD224 __attribute__((section(".data")));
extern s32 D_L01_001DD228 __attribute__((section(".data")));
extern s32 D_L01_001DD224_e __asm__("D_L01_001DD224") __attribute__((section(".data")));
extern f32 D_L01_001DD1C0[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD1C4[2];
extern vu0_q D_L01_001DD1E0[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD1B0, D_L01_001DD1B4, D_L01_001DD1B8;
void func_L01_003411A8_obj(u8 *obj) __asm__("func_L01_003411A8");
void func_L01_003411A8_obj(u8 *obj)
{
    extern void func_0038D328(f32 *, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern long func_00389598(s32);
    extern void func_003D2DA0(void *, void *, s32);
    Packet_003411A8 packet;
    f32 matrix[4][4];
    vu0_v4 angles, zero;
    u8 *vars;
    f32 width, height, extra;
    s32 color, i;
    *(vu0_q *)&zero = 0;
    vars = *(u8 **)(obj+0x68);
    zero.z = D_L01_001E29D8[0];
    *(vu0_q *)&angles = *(vu0_q *)&zero;
    func_0038D328(matrix[0], (f32 *)&angles);
    width = *(f32 *)(vars+8);
    height = (1.0f-width)*D_L01_001DD22C+1.0f;
    extra = D_L01_001DD230 * *(f32 *)(vars+12);
    width += extra;
    height += extra;
    func_0038CE20(matrix[0],matrix[0],width);
    func_0038CE20(matrix[1],matrix[1],width);
    func_0038CE20(matrix[2],matrix[2],height);
    *(vu0_q *)matrix[3] = *(vu0_q *)(obj+0x10);
    matrix[3][2] -= D_L01_001DD230 * *(f32 *)(vars+12) * 0.5f;
    matrix[3][3] = 1.0f;
    {
        f32 w = *(f32 *)(vars+8);
        if (w < 1.0f)
            color = func_0038DBD8(D_L01_001DD220,D_L01_001DD224,w);
        else color = func_0038DBD8(D_L01_001DD224_e,D_L01_001DD228,*(f32 *)(vars+12));
    }
    for (i=0;i<4;i++) {
        packet.color[i] = color;
        packet.uv[i][0] = D_L01_001DD1C0[i*2];
        packet.uv[i][1] = D_L01_001DD1C4[i*2];
        packet.vertex[i] = D_L01_001DD1E0[i];
    }
    packet.texture = func_00389598(D_L01_001DD1B0);
    packet.bits = ((long)D_L01_001DD1B4 << 2) | ((long)D_L01_001DD1B8 << 6) | 0x8000000000L;
    packet.alpha = 0xFF9000000260L;
    packet.mode = 5;
    func_003D2DA0(&packet,matrix,1);
    func_003D2DA0(&packet,matrix,1);
}
/* localdecomp:end func_L01_003411A8 */
