#include "common.h"

/* NTSC-U version of func_003A8440 (boot_elf): 150 -> 180; 1800 -> 2160 */
#include "common.h"


typedef int u128_t __attribute__((mode(TI)));



#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern void *D_U_001D7080;
/* localdecomp:start func_U_003A82F8 */
#include "vu0.h"
__asm__(".extern D_U_001D7080, 4");
typedef struct { u8 pad[0xAA]; s16 hAA; } O_003A8440;
typedef struct { u8 pad[0x20]; vu0_v4 *p20; u8 pad2[0x1C]; O_003A8440 *p40; } S_003A8440;
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 count;
    u8 pad46[0xA]; S_003A8440 *state; u8 pad54[0x14C]; O_003A8440 *objects[4];
} B_003A8440;
extern B_003A8440 D_U_00225780_003A8440;
extern vu0_v4 D_U_00222480_003A8440[];
extern void func_U_0038D328(void *, void *, void *);
extern void func_U_0038D290(void *, void *, f32);

void func_U_003A82F8(void) {
    O_003A8440 *m;
    vu0_v4 local;
    s32 lo = -1, hi = 9999, index = 0;
    s32 i;
    s32 j;

    if (D_U_00225780_003A8440.f30 == 0) {
        lo = 180;
        hi = 2160;
        index = 3;
    }
    if (D_U_00225780_003A8440.f34 > hi) {
        D_U_00225780_003A8440.state = 0;
    }
    if (D_U_00225780_003A8440.f34 >= lo && D_U_00225780_003A8440.f34 <= hi) {
        for (m = 0, i = 0; i < D_U_00225780_003A8440.count; i++) {
            O_003A8440 *o = D_U_00225780_003A8440.objects[i];
            if (o->hAA == 0xD54) {
                m = o;
                break;
            }
        }
        if (m) {
            for (j = 0; j < 4; j++) {
                func_U_0038D328(D_U_00225780_003A8440.state->p20 + j, (vu0_v4 *)D_U_001D7080 + j, (u8 *)m + 0xC0);
                vec_add_ba(D_U_00225780_003A8440.state->p20 + j, D_U_00225780_003A8440.state->p20 + j, (u8 *)m + 0x10);
                vec_sub_ab(&local, D_U_00222480_003A8440, D_U_00225780_003A8440.state->p20 + j);
                func_U_0038D290(&local, &local, 0.02f);
                vec_add_ba(D_U_00225780_003A8440.state->p20 + j, D_U_00225780_003A8440.state->p20 + j, &local);
            }
        }
        D_U_00225780_003A8440.state->p40 = D_U_00225780_003A8440.objects[index];
    }
}
/* localdecomp:end func_U_003A82F8 */
