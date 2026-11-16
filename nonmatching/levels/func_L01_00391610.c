/* PAL near miss (Codex wave 8): near miss: 15 words differ with the file's flags.
 * Worker's note: 15 diff: try3.log; constant reuse and loop-counter allocation differ (halfword/byte 255 merged); both pool strides and offsets decoded, full real draft.
 */
#include "common.h"
/* localdecomp:start func_L01_00391610 */
typedef struct { u8 pad[0x1C]; s32 active; u8 tail[0x10]; } Entry_00391610;
typedef struct { u8 pad[0x44]; s32 active; u8 tail[8]; } EntryB_00391610;
extern s32 D_L01_001DDFE8;
__asm__(".extern D_L01_001DDFE8, 4");
extern Entry_00391610 D_L01_0029EFA0[];
extern EntryB_00391610 D_L01_0029F1E0[];
void func_L01_00391610(void) {
    extern void *func_003C24B0(s32,s32);
    extern s32 func_L01_00424CB0(void *,f32,f32,f32,f32,f32);
    Moby_390240 *obj;
    u8 *p;
    s32 i;
    if(D_L01_001DDFE8==0) {
        obj=func_003C24B0(0x188D,0x80);
        if(obj) {
            { s16 distance=0xFF; obj->unk_32=distance; }
            { u8 mode=0xFF; obj->unk_30=mode; }
            p=(u8 *)obj->vars;
            obj->state=0;
            for(i=11;i>=0;i--)D_L01_0029EFA0[i].active=0;
            for(i=127;i>=0;i--)D_L01_0029F1E0[i].active=0;
            *(s32 *)(p+0x10)=func_L01_00424CB0(&obj->position,0.0f,0.0f,0.0f,0.0f,0.0f);
            D_L01_001DDFE8=(s32)obj;
        }
    }
}
/* localdecomp:end func_L01_00391610 */
