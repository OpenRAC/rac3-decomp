#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L23_003A4448 */
extern s32 D_L23_001DE098;
extern s32 D_L23_001DE09C;
extern f32 D_L23_001DE0A0;

void func_L23_003A4448(s32 arg0, s32 arg1, f32 fparg0) {
    D_L23_001DE098 = arg0;
    D_L23_001DE09C = arg1;
    D_L23_001DE0A0 = fparg0;
}
/* localdecomp:end func_L23_003A4448 */

LINKER_REMNANT("asm/levels", func_L23_003A4458);

INCLUDE_ASM("asm/levels", func_L23_003A4460);

INCLUDE_ASM("asm/levels", func_L23_003A5008);

INCLUDE_ASM("asm/levels", func_L23_003A5110);

/* localdecomp:start func_L23_003A5290 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003A5290(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x240);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003A5290 */

/* localdecomp:start func_L23_003A5328 */
extern float D_L23_001DE064;
__asm__(".extern D_L23_001DE064, 4");
extern float D_L23_001DE028;
__asm__(".extern D_L23_001DE028, 4");
extern s32 D_L23_001DE068;
__asm__(".extern D_L23_001DE068, 4");
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, float);
extern void func_003A52A0(s32, s32, void *);
extern void *func_L23_0032B060(void *, void *, void *, float);

void func_L23_003A5328(void *obj) {
    char matrix[64] __attribute__((aligned(16)));
    u128_t v[2];
    s32 i;

    for (i = 1; i < 3; i++) {
        func_003C2EC0(obj, i, matrix);
        v[0] = *(u128_t *)(matrix + 0x30);
        func_0038CF68(&v[1], matrix, D_L23_001DE064);
        func_003A52A0(2, 0, obj);
        func_L23_0032B060(&v[0], &v[1], &D_L23_001DE068, D_L23_001DE028);
    }
}
/* localdecomp:end func_L23_003A5328 */

INCLUDE_ASM("asm/levels", func_L23_003A53D0);

INCLUDE_ASM("asm/levels", func_L23_003A5590);

INCLUDE_ASM("asm/levels", func_L23_003A5750);
