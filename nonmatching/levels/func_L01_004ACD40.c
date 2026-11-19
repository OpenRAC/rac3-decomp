/* Near miss (6 diff): only the order of the first six instructions differs: retail loads 1.0f and sets the
 * loop counter before the lui/addiu of D_L01_001DF950; here the address comes first. Tried: loop forms, a
 * local for 1.0f, sized arrays, --as ps2as/newas, --mode N. Needs `#include "vu0.h"`-free plain C. */
typedef struct { u8 pad[0x20]; s16 h20, h22; } T_16C580;
extern T_16C580 D_0016C580_004ACD40;
extern f32 D_L01_001DF950[];
extern s32 D_L01_001E6D80[];
extern void func_L01_004AC900(s32);

void func_L01_004ACD40(void) {
    s32 i;

    for (i = 0; i >= 0; i--) {
        D_L01_001DF950[i] = 1.0f;
    }
    D_0016C580_004ACD40.h20 = 0;
    D_0016C580_004ACD40.h22 = -1;
    func_L01_004AC900(3);
    D_L01_001E6D80[13] = 1;
}
