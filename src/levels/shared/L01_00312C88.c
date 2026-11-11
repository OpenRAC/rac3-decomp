#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_00312C88 */
extern u8 *D_L01_001E1730_00312C88;
extern s32 func_0038CAD0(void *);
extern s32 func_0013D3E0(void);
extern void func_L01_00312DD8(void *, s32, f32, f32, s32);
extern void func_L01_00313270(void *);

void func_L01_00312C88(s32 a0) {
    s32 i;
    for (i = 0; i < 1; i++) {
        u8 *e = (u8 *)(i * 80 + (s32)D_L01_001E1730_00312C88);
        if (*(s32 *)(e + 48) == a0) {
            if (func_0038CAD0(e + 52) != 0) {
                if (*(s32 *)(e + 56) == 0) {
                    *(s32 *)(e + 48) = 0;
                }
            } else if (!(func_0013D3E0() & 1)) {
                func_L01_00312DD8(e, 0, 0.0f, 0.0f, 0);
                func_L01_00312DD8(e, 0, 0.0f, 0.0f, 0);
            }
            func_L01_00313270(e);
        }
    }
}
/* localdecomp:end func_L01_00312C88 */

/* localdecomp:start func_L01_00312D70 */
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
extern void func_L01_00313598(s32 id);
extern u8 *D_L01_001E1730_00312D70;
void func_L01_00312D70_00312D70(s32 id) __asm__("func_L01_00312D70");
void func_L01_00312D70_00312D70(s32 id) {
    s32 i;
    for (i = 0; i < 1; i++) {
        if ((*(Ent_00312A80 * *)&D_L01_001E1730_00312D70)[i].id == id) ((void (*)(Ent_00312A80 *))func_L01_00313598)(&(*(Ent_00312A80 * *)&D_L01_001E1730_00312D70)[i]);
    }
}
/* localdecomp:end func_L01_00312D70 */
