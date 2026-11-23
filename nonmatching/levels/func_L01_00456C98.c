/* PAL near miss (sol-round3-b): 339 words differ with the file flags; retail uses quadword register saves and a 0xf0 frame. Game state and candidate loops still differ in address formation and scheduling. */
#include "common.h"
/* localdecomp:start func_L01_00456C98 */
typedef int Q_00456C98 __attribute__((mode(TI)));
typedef struct { Q_00456C98 pos; u8 *target; s16 valid; u8 pad16[6]; s16 kind; } Target_00456C98;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 4");
extern s32 D_L01_001D6774;
extern s16 D_L01_001E0180[32];
extern s16 D_L01_001E01C0[32];
extern u8 *D_L01_001E001C;
extern void *D_L01_001EFFE8[];
extern int D_L01_001F01E8[];
s32 func_L01_00456C98(u8 *obj, s32 id, void *position, s32 force, s32 mode, s32 same, s32 team, s32 option, f32 radius, f32 height, f32 scale, u8 ray, u8 extra) {
    extern M_453408 *func_L01_00456910(M_453408 *, s32, s32 *, s32, s32, s32, s32, s32, f32);
    extern f32 func_L01_004566F8(M_453408 *, M_453408 *, s32, s32, s32, s32, f32);
    extern int func_L01_00456B40(u8 *, u8 *, f32, f32);
    extern V_453408 *func_00382348(M_453408 *);
    extern void func_L01_00450E48(void *, void *, f32, f32, f32);
    s32 kind;
    Q_00456C98 origin;
    Target_00456C98 *out;
    u8 *item;
    u8 *best;
    s32 best_kind;
    s32 i;
    f32 score, distance;
    V_453408 *vars;
    if (!(*(u16 *)(obj + 0x34) & 0x20)) return 0;
    out = *(Target_00456C98 **)(*(u8 **)(obj + 0x68) + 0xC);
    if (position) origin = *(Q_00456C98 *)position;
    else origin = *(Q_00456C98 *)(obj + 0x10);
    out->pos = *(Q_00456C98 *)((u8 *)&D_001A4BE0 + 0xD0);
    out->target = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
    out->kind = 0;
    out->valid = 0;
    if (!force) {
        if (D_L01_001D6694) return 0;
        if (*(s32 *)((u8 *)&D_001A4BE0 + 0x25C4) == 116) return 0;
    }
    if (id != -1) {
        item = (u8 *)func_L01_00456910((M_453408 *)obj,id,&kind,team,mode,option,ray,extra,scale);
        if (!item) return out->valid;
        if (mode) {
            if (item == *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0)) return out->valid;
            if (same && *(s16 *)(item+0xAA) == *(s16 *)(obj+0xAA)) return out->valid;
            out->target = item;
            out->valid = 1;
            out->kind = *(u16 *)&kind;
            if (item != *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0)) {
                out->pos = *(Q_00456C98 *)(item+0x10);
                vars = func_00382348((M_453408 *)item);
                if (vars) {
                    if (D_L01_001D673C) func_L01_00450E48(item,out,0.0f,0.0f,*(f32 *)((u8 *)vars+0x10));
                    else *(f32 *)((u8 *)out+8) += *(f32 *)((u8 *)vars+0x10);
                }
            }
        } else {
            if (same && *(s16 *)(item+0xAA) == *(s16 *)(obj+0xAA)) return out->valid;
            out->target = item;
            out->valid = 1;
            out->kind = *(u16 *)&kind;
            out->kind = *(u16 *)&kind;
            if (item != *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0)) {
                out->pos = *(Q_00456C98 *)(item+0x10);
                vars = func_00382348((M_453408 *)item);
                if (vars) {
                    if (D_L01_001D673C) func_L01_00450E48(item,out,0.0f,0.0f,*(f32 *)((u8 *)vars+0x10));
                    else *(f32 *)((u8 *)out+8) += *(f32 *)((u8 *)vars+0x10);
                }
            }
        }
    } else {
        if (*(s32 *)((u8 *)&D_001A4BE0 + 0x25C4) == 49) height = 60.0f;
        distance = 9999999.0f;
        best = 0;
        best_kind = 0;
        if (!mode) {
            item = *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0);
            if (func_L01_00456B40(item,(u8 *)&origin,radius,height)) {
                score = func_L01_004566F8((M_453408 *)obj,(M_453408 *)item,0,0,ray,extra,scale);
                if (score < distance) { best = item; best_kind = 1; distance = score; }
            }
        }
        if (!mode) {
            for (i=1;i<=D_L01_001E0180[0];i++) {
                item = D_L01_001E001C + (D_L01_001E0180[i]<<8);
                if (item && *(s16 *)(item+0xAA)==203 && item[0x20]!=254 && item[0x20]!=253 && item[0x20]==3) {
                    if (func_L01_00456B40(item,(u8 *)&origin,radius,height)) {
                        score=func_L01_004566F8((M_453408 *)obj,(M_453408 *)item,mode,0,ray,extra,scale);
                        if (score<distance) { best=item; best_kind=2; distance=score; }
                    }
                }
            }
        }
        for (i=0;i<D_L01_001D6774;i++) {
            item=D_L01_001EFFE8[i];
            if (same && *(s16 *)(item+0xAA)==*(s16 *)(obj+0xAA)) continue;
            if (func_L01_00456B40(item,(u8 *)&origin,radius,height) && item && item[0x20]!=254 && item[0x20]!=253 && item!=obj) {
                score=func_L01_004566F8((M_453408 *)obj,(M_453408 *)item,mode,0,ray,extra,scale);
                if (score<distance) {
                    if (team) {
                        if (D_L01_001F01E8[i]!=team) continue;
                        best=item; best_kind=D_L01_001F01E8[i]; distance=score;
                    } else { best=item; best_kind=3; distance=score; }
                }
            }
        }
        if (!mode) {
            for(i=1;i<=D_L01_001E01C0[0];i++) {
                item=D_L01_001E001C+(D_L01_001E01C0[i]<<8);
                if(item && *(s16 *)(item+0xAA)==7107 && item[0x20]!=254 && item[0x20]!=253) {
                    if(func_L01_00456B40(item,(u8 *)&origin,radius,height)) {
                        score=func_L01_004566F8((M_453408 *)obj,(M_453408 *)item,mode,0,ray,extra,scale);
                        if(score<distance) {best=item;best_kind=4;distance=score;}
                    }
                }
            }
        }
        if(best) {
            out->valid=1;out->kind=best_kind;out->target=best;
            if(best==*(u8 **)((u8 *)&D_001A4BE0+0x25C0)) out->pos=*(Q_00456C98 *)((u8 *)&D_001A4BE0+0xD0);
            else {
                out->pos=*(Q_00456C98 *)(best+0x10);
                vars=func_00382348((M_453408 *)best);
                if(vars) {
                    if(D_L01_001D673C) func_L01_00450E48(best,out,0.0f,0.0f,*(f32 *)((u8 *)vars+0x10));
                    else *(f32 *)((u8 *)out+8)+=*(f32 *)((u8 *)vars+0x10);
                }
            }
        }
    }
    return out->valid;
}
/* localdecomp:end func_L01_00456C98 */
