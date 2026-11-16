/* PAL near miss (Codex wave 10): near miss: 182 words differ with the file's flags.
 * Worker's note: 182 raw diff (try04.log); folded initial table+4 address loses one instruction, s5/s6 allocation and address-add order remain; three wordings emit same residual; switch 0/1/2 evidenced in asm.txt
 */
#include "common.h"
/* localdecomp:start func_L07_003323F8 */
extern u8 D_L07_002B0D40[8];
typedef struct { u8 pad[0x44]; s32 ids[3]; u8 pad50[0x4e]; u8 group, current; } State_003323F8;
extern u8 D_L07_001DCEB8[4];
__asm__(".extern D_L07_001DCEB8, 4");
extern s32 D_L07_001DF458_003323F8;
extern u8 *D_L07_001DF41C_003323F8;
extern u16 *D_L07_0021C020[];
void func_L07_003323F8(u8 *object) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern void func_L07_003A2380(u8, u8 *, s32, s32);
    extern u8 *func_L07_00333B20(u8 *);
    State_003323F8 *state = *(State_003323F8 **)(object+0x68);
    u8 *colors = D_L07_001DCEB8 + (*(u8 **)(state->group*16+(s32)D_L07_002B0D40+4))[state->current*12+1]*3;
    s32 spoken = 0;
    s32 i, n;
    u16 *p;
    u8 *entry;
    for (i=0; i<3; i=n) {
        if (state->current && colors[i] != 1 && colors[i] != (D_L07_001DCEB8+(*(u8 **)(D_L07_002B0D40+state->group*16+4))[state->current*12-11]*3)[i] && !spoken && func_00382468(2)) {
            switch(i) {
                case 0:
                    func_L07_003A2380((u8)(colors[0]==2 ? func_00382498(35,36) : func_00382498(29,30)), object, 0, 100);
                    break;
                case 1:
                    func_L07_003A2380((u8)func_00382498(31,32), object, 0, 100);
                    break;
                case 2:
                    func_L07_003A2380((u8)func_00382498(33,34), object, 0, 100);
                    break;
            }
            spoken=1;
        }

        for(p=D_L07_0021C020[state->ids[i]];
            (state->ids[i]&255)!=255 && state->ids[i]<=D_L07_001DF458_003323F8 && p &&
            ((s16)p[-1]>=0 || p==D_L07_0021C020[state->ids[i]]); p++) {
            entry=D_L07_001DF41C_003323F8+((*p&0x7fff)<<8);
            if(!entry) break;
            func_L07_00333B20(entry)[8]=colors[i];
        }
        n=i+1;
    }
}
/* localdecomp:end func_L07_003323F8 */
