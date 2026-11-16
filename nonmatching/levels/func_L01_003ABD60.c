/* PAL near miss (Codex wave 8): near miss: 64 words differ with the file's flags.
 * Worker's note: 21 diff; best w449/func_L01_003ABD60.c08-detail.log with injected divs 1 2 1 0; float register allocation and negative-boundary temporary differ; no exact metadata claim
 */
#include "common.h"
/* localdecomp:start func_L01_003ABD60 */
typedef struct { s32 count; u8 pad[0x18]; f32 length; } Path_003ABD60;
f32 func_L01_003ABD60(u8 *object, Path_003ABD60 *path, s32 *index, f32 position, f32 distance) {
    f32 boundary=0.0f;
    f32 step;
    f32 remaining=1.0f;
    do {
        if(position<0.0f) {
            *index=-1;
            step=(distance / *(f32 *)(object+0xd6c))*remaining;
            if(boundary<=position+step) {
                boundary=boundary-position;
                boundary=boundary/step;
                remaining-=boundary*remaining;
                position=0.0f;
                *index=0;
            } else {
                position+=step;
                remaining=0.0f;
            }
        } else {
            s32 segment=(s32)position;
                        f32 end;
            *index=segment;
            boundary=(f32)segment;
            step=(distance/((Path_003ABD60 *)((s32)path+(segment<<4)))->length)*remaining;
            end=position+step-boundary;
            if(end>=1.0f && segment<path->count-1) {
                f32 ratio=(step-(end-1.0f))/step;
                position+=step*ratio;
                remaining-=ratio*remaining;
                *index=(s32)position;
            } else {
                position+=step;
                remaining=0.0f;
            }
        }
    } while((boundary=0.0f)<remaining);
    return position;
}
/* localdecomp:end func_L01_003ABD60 */
