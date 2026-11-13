#include "common.h"

/* localdecomp:start func_L39_005C32A0 */
typedef struct {
    u8 pad0[0x198];
    s32 x198;
    u8 pad19C[0x54C - 0x19C];
    u8 x54C;
    u8 pad54D[3];
    u8 x550;
    u8 pad551[6];
    u8 x557;
    u8 pad558[0x56C - 0x558];
    s32 x56C;
    s32 x570;
    u8 pad574[0x5C0 - 0x574];
} S_005C32A0;

extern S_005C32A0 D_L39_00225780[];
extern S_005C32A0 *D_L39_00241164;
extern S_005C32A0 *D_L39_00241168;
extern S_005C32A0 *D_L39_0024116C;

__asm__(".extern D_L39_00241164, 16");
__asm__(".extern D_L39_00241168, 16");
__asm__(".extern D_L39_0024116C, 16");

extern void func_0013BF90(void);
extern void func_0013C268(s32);
extern void func_0013C0B0(s32);
extern s32 func_0013C190(s32);
extern s32 func_0013C690(s32, s32, S_005C32A0 *);
extern void func_003A2CD8(S_005C32A0 *);

void func_L39_005C32A0(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 buf[2];

    func_0013BF90();
    func_0013C268(0);
    func_0013C0B0(0);
    buf[0] = func_0013C190(0);
    func_0013C0B0(1);
    buf[1] = func_0013C190(1);
    i = 0;
    do {
        a = i > 3;
        b = i % 4;
        func_003A2CD8(&D_L39_00225780[i]);
        func_0013C690(a, b, &D_L39_00225780[i]);
        D_L39_00225780[i].x557 = b;
        D_L39_00225780[i].x54C = a;
        D_L39_00225780[i].x198 = 0;
        D_L39_00225780[i].x550 = buf[a];
        D_L39_00225780[i].x56C = 0;
        D_L39_00225780[i].x570 = 0;
        i++;
    } while (i < 8);
    D_L39_00241164 = D_L39_00225780;
    D_L39_0024116C = D_L39_00241168 = D_L39_00225780 + 4;
}
/* localdecomp:end func_L39_005C32A0 */
