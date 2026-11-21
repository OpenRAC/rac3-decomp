/* functional: high. Read block by block against the PAL asm (loop, constants, vector helper calls, z restore); 33 words differ only in scheduling around the VU0 blocks. */
#include "common.h"
#include "vu0.h"
static __inline__ void vec_sub_ab_00476F10(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf1, $vf2\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_sub_ba_00476F10(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
static __inline__ void vec_add_ab_00476F10(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_add_ba_00476F10(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
extern int D_L01_0021F6C0[];
s32 func_L01_00476F10(s32 index, vu0_v4 *src, vu0_v4 *out, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CE68(void *, void *);
    vu0_v4 delta, temp, pos, dir, norm, cross, closest;
    s32 changed=0;
    s32 i;
    u8 *point;
    f32 len, projection;
    *(vu0_q *)&pos=*(vu0_q *)src;
    for(i=0;i<*(s32 *)D_L01_0021F6C0[index]-1;i++) {
        point=(u8 *)D_L01_0021F6C0[index]+(i<<4);
        if(*(f32 *)(point+0x1C)!=0.0f) {
            vec_sub_ba_00476F10(&delta,&pos,point+0x10);
            delta.z=0.0f;
            vec_sub_ba_00476F10(&dir,point+0x20,point+0x10);
            dir.z=0.0f;
            func_0038CF68(&norm,&dir,1.0f);
            func_0038CE90(&cross,&delta,&norm);
            if(!(radius<fabs_asm(cross.z))) {
                len=func_0038CEA8(&dir);
                projection=func_0038CE68(&delta,&norm);
                if(projection>len || projection<0.0f) {
                    if(func_0038CEA8(&delta)<radius) {
                        func_0038CF68(&temp,&delta,radius);
                        changed=1;
                        vec_add_ab_00476F10(&pos,&temp,(u8 *)D_L01_0021F6C0[index]+(i<<4)+0x10);
                        pos.z=src->z;
                    }
                } else {
                    func_0038CF68(&closest,&norm,projection);
                    changed=1;
                    vec_sub_ba_00476F10(&temp,&delta,&closest);
                    func_0038CF68(&temp,&temp,radius);
                    vec_add_ba_00476F10(&temp,&temp,&closest);
                    vec_add_ba_00476F10(&pos,&temp,(u8 *)D_L01_0021F6C0[index]+(i<<4)+0x10);
                    pos.z=src->z;
                }
            }
        }
    }
    if(changed) *(vu0_q *)out=*(vu0_q *)&pos;
    return changed;
}
