#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_0034BE60 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x1A];
    u16 h2A;
    u8 pad2C[0x14];
} S_0034BE60;

extern char *D_L30_001E9018 __attribute__((section(".data")));
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004450F0(char *, s32, s32);
extern void func_L01_00446760(void *, char *, s32, char *, f32);
extern s32 func_003D3CB0(void *, void *, s32, char *, void *);
extern s32 func_L01_003FB640(void *, s32, char *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00446780(char *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L30_0034DAC0(void *);
extern void func_003C2880(char *);
void func_L30_0034C040(char *);
void func_L30_0034C0E8(char *);

void func_L30_0034BE60(char *a0) {
    char *s3 = *(char **)(a0 + 0x68);
    S_0034BE60 buf;
    char *p;

    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(s32 *)(s3 + 0x28) = -1;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 0.12566371f);
        vec_add_ba(&buf.pos, a0 + 0x10, s3);
        func_L01_00446760(buf.pad10, a0, 1, s3, *(f32 *)(s3 + 0x18));
        buf.h2A = *(u16 *)(a0 + 0xAA);
        if (func_003D3CB0(a0 + 0x10, &buf, 0, a0, buf.pad10) == 0
            && func_L01_003FB640(a0 + 0x10, 0, a0, 0.3f) == 0
            && func_0038CAD0(s3 + 0x10) == 0) {
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&buf.pos;
        } else {
            p = D_L30_001E9018;
            if (p == 0) {
                func_L01_004450F0(a0, 2, -1);
                return;
            }
            if (p != *(char **)(s3 + 0x14) && *(s16 *)(p + 0xAA) != 0x15F9) {
                func_L01_00446780(a0, a0 + 0x10, 1, 0, 1, 0, 0.5f, *(f32 *)(s3 + 0x18), 1.0f);
                func_L01_004450F0(a0, 2, -1);
                return;
            }
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)&buf.pos;
        }
        break;
    case 2:
        func_L30_0034DAC0(s3 + 0x28);
        func_003C2880(a0);
        return;
    }
    func_L30_0034C040(a0);
    func_L30_0034C0E8(a0);
}
/* localdecomp:end func_L30_0034BE60 */
