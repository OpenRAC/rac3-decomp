/* PAL near miss (Codex wave 6): near miss: 222 words differ with the file's flags.
 * Worker's note: 221 diff with metadata 2,0,2 (w283/func_L01_00439E10.final.log); fixed default assembler uses lit4 for 0.99/1.01 versus retail inline lui/ori/mtc1; register and loop alignment differences remain. Verbatim later owner types required in snippet; not ...
 */
#include "common.h"
/* localdecomp:start func_L01_00439E10 */
typedef struct {
    u8 pad_0[0x41];
    u8 keyframe;                   
    u8 pad_42;
    u8 sequence;                   
} Moby_43A1E8;
typedef struct {
    u8 pad_0[0x20];
    u8 from_keyframe;              
    u8 to_keyframe;                
    u8 from_sequence;              
    u8 to_sequence;                
    s32 time;                      
    f32 blend;                     
    f32 blend_rate;                
} Layer_43A1E8;
typedef struct {
    u8 pad0[6];
    s16 h6;
    s16 h8;
    s16 h10;
    s16 h12;
    s16 h14;
    unsigned long q[1];
} S_437200_B;
typedef struct {
    u8 pad0[28];
    S_437200_B *arr[1];
} S_437200_E;
typedef struct {
    u8 pad0[4];
    u8 idx[1];
} S_437200_I;
typedef struct {
    u8 pad0[8];
    u8 cnt;
    u8 pad9[19];
    S_437200_I *ix;
    u8 pad20[40];
    S_437200_E *arr[1];
} S_437200_H;
typedef struct {
    u8 pad0[8];
    u8 cnt;
} S_437200_C;
typedef struct {
    u8 pad0[20];
    S_437200_C *c;
    S_437200_H *h;
} S_437200_O;

typedef struct {
    u8 pad[0x10];
    u8 count, pad11[2], mode;
    u8 pad14[8];
    void *frames[1];
} Seq_00439E10;
typedef struct {
    u8 pad[8]; u8 count; u8 pad9[0x3f];
    Seq_00439E10 *seq[1];
} Anim_00439E10;
typedef struct {
    s16 id, count;
    u8 state, flags, from_custom, to_custom;
    u8 pad8[8];
    void *dest;
    Anim_00439E10 *anim;
    u8 pad18[8];
    u8 from_frame, to_frame, from_seq, to_seq;
    f32 time, blend, rate;
    u8 pad30[8];
    void *from_data, *to_data;
} Layer_00439E10;
void func_L01_00439E10(Moby_43A1E8 *moby, Layer_43A1E8 *arg) {
    extern void func_0011F0A0(s32);
    extern void func_L01_0043A2E0(S_437200_O *, s32, s32, S_437200_B *);
    extern void func_L01_0043C8F8(void *, void *, void *, s32);
    extern void func_L01_0043E8D0(void *);
    extern void func_L01_00441658(void *, void *, s32, f32);
    Layer_00439E10 *l = (Layer_00439E10 *)arg;
    f32 step, old_time, weight;
    void *dest, *old_data;
    Seq_00439E10 *s;
    Anim_00439E10 *anim;
    s16 *frame;
    l->flags = 0;
    step = l->blend * l->rate;
    if (step != 0.0f) {
        l->time += step;
        if (l->time > 0.99f && l->time < 1.01f) l->time = 1.0f;
        if (l->time >= 1.0f) {
            do {
                l->flags |= 1;
                l->from_frame = l->to_frame;
                if (l->to_custom && !l->from_custom) l->from_data = l->to_data;
                l->from_custom = l->to_custom;
                l->from_seq = l->to_seq;
                l->to_frame++;
                if (l->to_frame >= l->anim->seq[l->to_seq]->count) {
                    l->to_frame = 0;
                    l->flags |= 2;
                }
                l->time = (l->time - 1.0f) / l->rate;
                s = l->anim->seq[l->from_seq];
                if (s->mode == 255) l->rate = *(f32 *)s->frames[l->from_frame];
                else {
                    frame = (s16 *)((u32)s->frames[l->from_frame] & 0x0fffffff);
                    if (*frame == 0) l->rate = 0.0f;
                    else l->rate = 1.0f / *frame;
                }
                l->time *= l->rate;
            } while (l->time >= 1.0f);
        }
    }
    if (l->to_custom) func_L01_0043A2E0((S_437200_O *)l,l->to_seq,l->to_frame,(S_437200_B *)l->to_data);
    else {
        anim = l->anim;
        s = anim->seq[l->to_seq];
        if (s->mode == 255) l->to_data = s->frames[l->to_frame];
        else {
            func_L01_0043C8F8((u8 *)&s->frames[s->count] + s->mode*4,s->frames[l->to_frame],l->to_data,anim->count);
            func_0011F0A0(0);
        }
    }
    if (l->from_seq == 255) {
        old_time = l->time;
        weight = 1.0f - (old_time - step);
        dest = l->dest;
        old_data = l->from_data;
        l->time = 0;
        l->dest = 0;
        l->from_data = l->to_data;
        weight = step / weight;
        func_L01_0043E8D0(l);
        l->time = old_time;
        l->from_data = old_data;
        l->dest = dest;
        func_L01_00441658(dest,(void *)0x70000000,l->count,weight);
    } else {
        if (l->from_custom) func_L01_0043A2E0((S_437200_O *)l,l->from_seq,l->from_frame,(S_437200_B *)l->from_data);
        else {
            anim = l->anim;
            s = anim->seq[l->from_seq];
            if (s->mode == 255) l->from_data = s->frames[l->from_frame];
            else {
                func_L01_0043C8F8((u8 *)&s->frames[s->count] + s->mode*4,s->frames[l->from_frame],l->from_data,anim->count);
                func_0011F0A0(0);
            }
        }
        func_L01_0043E8D0(l);
    }
    l->state = 2;
}
/* localdecomp:end func_L01_00439E10 */
