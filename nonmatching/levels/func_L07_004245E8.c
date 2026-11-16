/* PAL near miss (Codex wave 7): near miss: 28 words differ with the file's flags.
 * Worker's note: 28 diff best actual: build/codex/w343/func_L07_004245E8.a9.log; initial store scheduling, case0 register allocation, long index extension and end-list gp/lui remain; PAL switch table decoded in .switch.txt; 10 attempts
 */
#include "common.h"
/* localdecomp:start func_L07_004245E8 */
typedef struct Menu_004245E8 { u8 pad[0x20]; s32 text; u8 pad24[12]; s32 enabled; u8 pad34[12]; s32 id; } Menu_004245E8;
typedef struct State_004245E8 { u8 pad[0x30]; u32 mode; s32 count; } State_004245E8;
typedef struct Moby_004245E8 { u8 pad[0xAA]; s16 id; u8 tail[0x54]; } Moby_004245E8;
extern Menu_004245E8 D_L07_002E85A0[], D_L07_002E85F0[], D_L07_002E8660[], D_L07_002E86C0[], D_L07_002E88E0[];
extern char D_L07_002E8720[];
extern s32 D_L07_001D6AB0, D_L07_001D6B88, D_L07_001D6B70, D_L07_001D6BA0;
extern s32 D_L07_001D6B74;
__asm__(".extern D_L07_001D6B74, 16");
extern f32 D_L07_001D6B44;
extern u8 D_L07_001D6AA5;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern State_004245E8 D_L07_001E6200[];
extern Moby_004245E8 *D_L07_001DF41C[], *D_L07_001DF420[];
extern Moby_004245E8 *D_L07_001DF420_004245E8;
void func_L07_004245E8(void) {
    extern void func_L01_00423068(void *, void *, s32, s32, void *, s32, s32);
    extern void func_L03_004109D8(void *, void *, s32, s32);
    Menu_004245E8 *menu = 0;
    s32 *value = 0;
    Menu_004245E8 *other = 0;
    Moby_004245E8 *m;
    long index;
    Moby_004245E8 *end;
    D_L07_002E85A0[0].text = (s32)&D_L07_001D6AB0;
    D_L07_002E85A0[0].enabled = 1;
    D_L07_001D6B44 = 1.0f;
    D_L07_001D6AA5 = 0;
    if (D_001D545C == 7) {
        switch (D_L07_001E6200[0].mode) {
        case 0:
            value = &D_L07_001D6B88;
            if ((D_L07_001D6B74 * 5 + 2) / 6 >= D_L07_001E6200[0].count) value = &D_L07_001D6B70;
            other = D_L07_002E85F0;
            break;
        case 1: menu = D_L07_002E8660; break;
        case 2: menu = D_L07_002E86C0; break;
        case 3:
            if (D_L07_001E6200[0].count >= (D_L07_001D6BA0 * 5 + 2) / 6) {
                value = &D_L07_001D6BA0;
                other = D_L07_002E85F0;
            }
            break;
        case 4:
            D_L07_002E85A0[0].text = (s32)D_L07_002E8720;
            menu = D_L07_002E88E0;
            index = 0;
            m = D_L07_001DF41C[0];
            if (m < D_L07_001DF420[0]) {
                do {
                    if (m && m->id == menu->id) {
                        func_L01_00423068(menu, 0, 0, 0, m, 7, index);
                        index++;
                    }
                    m++;
                } while (m < D_L07_001DF420_004245E8);
            }
            menu = 0;
            break;
        }
    }
    if (menu) func_L01_00423068(menu, value, 0, 0, 0, 1, 0);
    else if (other) func_L03_004109D8(other, value, 0, 0);
}
/* localdecomp:end func_L07_004245E8 */
