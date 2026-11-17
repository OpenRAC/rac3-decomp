#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_00325BA0;

/* localdecomp:start func_L02_00325BA0 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L02_001DE2DC;
extern G_00325BA0 D_001CCFD0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L02_004C2D20(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
void func_L02_00325BA0(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;
    v[0] = func_0038D098(*(f32 *)(q + 0x1C)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x1C)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q + 0x10);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x1C), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L02_004C2D20(0);
    }
    func_L01_004F50C8(v, w, 0x74, 0);
    func_003A52A0(0, 0, a0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x1C)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x1C)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x1C), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x1C), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q + 0x10);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x1C), 1.5707964f);
    func_L01_003EB438(0, v2, w2, 1, 0, 0);
    func_L01_003EB350(0, v2);
    func_L01_003EB3C0(0, w2);
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(h + 0x80);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 0, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L02_001DE2DC = 1;
    a0[0x20] = 2;
    *(s32 *)(q + 0x6C) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L02_00325BA0 */

/* localdecomp:start func_L02_00325E90 */
#include "vu0.h"
#include "structs/moby.h"
extern s32 D_001D545C_sda;
extern u8 D_001BBB18[];
extern f32 D_L02_001DC8F0_00325E90, D_L02_001DC8F4_00325E90, D_L02_001DC8F8_00325E90;
extern f32 D_L02_001DC8FC_00325E90, D_L02_001DC900_00325E90, D_L02_001DC904_00325E90, D_L02_001DC908_00325E90;
extern s32 D_L02_001DE5B8, D_L02_001DE6B8;
extern u16 D_001A8EB0[];
extern s16 D_001A4F4E[];
__asm__(".extern D_L02_001DC8F0_00325E90, 4");
__asm__(".extern D_L02_001DC8F4_00325E90, 4");
__asm__(".extern D_L02_001DC8F8_00325E90, 4");
__asm__(".extern D_L02_001DC8FC_00325E90, 4");
__asm__(".extern D_L02_001DC900_00325E90, 4");
__asm__(".extern D_L02_001DC904_00325E90, 4");
__asm__(".extern D_L02_001DC908_00325E90, 4");
typedef struct Pvars_00325E90 {
 s32 index; u8 pad4[8]; s16 hC; u8 padE[2];
 f32 pos[4]; u8 pad20[0x40]; f32 f60,f64,f68; s32 timer;
 u8 pad70[8]; s32 i78;
} Pvars_00325E90;
void func_L02_00325E90(u8 *p)
{
    extern void func_L02_00325BA0(u8 *);
    extern f32 func_00382538(void);
    extern void func_L02_00326520(u8 *);
    extern void func_L02_00326600(u8 *);
    extern void func_L02_00326A80(u8 *);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00451F60(s32,s32,s32);
    extern void func_003A1F30(void);
    extern void func_L01_0041A5B0(s32,s32);
    extern void func_L02_00326BD8(void);
    extern void func_0039EC28(s32,s32);
    extern void func_003C2880(void *);
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L02_00326878(void *);
    extern void func_L02_00326430(void *);
    extern s32 func_00382468(s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_003EB5E0(s32,s32);
    struct Moby *m=(struct Moby *)p;
    Pvars_00325E90 *q = m->pvar;
    u8 *h,*tail,*hero_pos,*hero_base;
    s32 i;
    f32 distance;
    switch (((u8 *)m)[0x20]) {
    case 0:
        if (q->index == -1 || D_001BBB18[q->index + D_001D545C_sda*8]) {
            func_003C2880(p);
            break;
        }
        *(u128_t *)(q->pos) = *(u128_t *)(p+0x10);
        q->pos[3] = m->rotation.z;
        m->rotation.x = func_00382538();
        m->rotation.y = func_00382538();
        m->rotation.z = func_00382538();
        m->rotation.w = func_00382538();
        q->f68=D_L02_001DC8FC_00325E90*0.017453292f*0.020000001f;
        q->f64=D_L02_001DC900_00325E90*0.017453292f*0.020000001f;
        q->f60=D_L02_001DC904_00325E90*0.017453292f*0.020000001f;
        if (m->draw_dist < 0x40) m->draw_dist = 0x40;
        ((u8 *)m)[0x20] = 1;
        func_L02_00326520(p);
        break;
    case 1:
        m->scale = *(f32 *)(*(u8 **)(p+0x24)+0x24)*D_L02_001DC8F0_00325E90;
        m->position.z = q->pos[2] + D_L02_001DC8F4_00325E90 + D_L02_001DC8F8_00325E90 * func_0038D0B0(m->rotation.w);
        m->rotation.x = func_0038DAB8(m->rotation.x,D_L02_001DC8FC_00325E90*0.017453292f*0.020000001f);
        m->rotation.y = func_0038DAB8(m->rotation.y,D_L02_001DC900_00325E90*0.017453292f*0.020000001f);
        m->rotation.z = func_0038DAB8(m->rotation.z,D_L02_001DC904_00325E90*0.017453292f*0.020000001f);
        m->rotation.w = func_0038DAB8(m->rotation.w,D_L02_001DC908_00325E90*0.017453292f*0.020000001f);
        func_L02_00326600(p);
        func_L02_00326A80(p);
        hero_pos = D_001A4BE0+0x80;
        distance=func_0038CF38(p+0x10,hero_pos);
        if (distance < 3.0f && (hero_base=hero_pos-0x80, fabs_asm(m->position.z-*(f32 *)(hero_base+0x88)) < 2.0f) && *(s32 *)(hero_base+0x2850) && (hero_base[0x25E4] == 3 || hero_base[0x25E4] == 0)) {
            if (q->hC == 0 && *(s32 *)(hero_base+0x25C4) != 0x31) goto blocked;
                D_L02_001DE5B8=0x96;
                func_L01_00451F60(0xC93,-1,0);
                if (!D_001A8EB0[0]) {
                    if ((u32)((u16)D_001CCFD0.h76-6)>=2) D_001CCFD0.h76=5;
                    if ((u32)((u16)D_001CCFD0.h9E-6)>=2) D_001CCFD0.h9E=5;
                    func_003A1F30();
                    func_L01_0041A5B0(0x1911,0x162);
                }
                D_001BBB18[q->index+D_001D545C_sda*8]=1;
                func_L02_00326BD8();
                func_0039EC28(0,-1);
                func_003A52A0(1,0,p);
                func_003C2880(p);
            break;
blocked:
            if (q->i78) {
                m->mode_flags |= 0x41;
                func_L01_004450F0(p,3,-1);
            } else func_L02_00325BA0(p);
        }
        break;
    case 3:
        if (!D_001A4F4E[0]) func_L02_00325BA0(p);
        break;
    case 2:
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) func_003A1798();
        h=D_001A4BE0;
        D_L02_001DE6B8=1;
        *(s16 *)(h+0x1DC)=3;
        func_L02_00326878(p);
        *(u128_t *)(p+0x10)=*(u128_t *)(h+0x80);
        *(u128_t *)(p+0xF0)=*(u128_t *)(h+0x90);
        if (m->prev_seq==1) {
            func_L02_00326430(p);
            if (!func_00382468(10)) func_L02_00326A80(p);
            if (m->anim_flags&2) {
                if (m->cur_seq) func_003C3A10(p,0,0,0);
                p[0x31]=0;
                m->mode_flags|=1;
                for(i=3;i>=0;i--) func_L02_00326A80(p);
            }
        }
        tail=D_001A4BE0;
        if (*(s32 *)(tail+0xC08)&2) func_L01_0050FB40(0,0,25.0f);
        if (m->prev_seq==0 && func_0038CAD0(&q->timer)) {
            D_L02_001DE5B8=0x96;
            func_L01_00451F60(0xC93,-1,0);
            if (!D_001A8EB0[0]) func_L01_0041A5B0(0x1911,0x162);
            D_001BBB18[q->index+D_001D545C_sda*8]=1;
            func_L02_00326BD8();
            D_L02_001DE2DC=0;
            func_L01_004F50C8(tail+0x80,tail+0x90,0,0);
            func_L01_003EB5E0(0,0);
            func_0039EC28(0,-1);
            func_003C2880(p);
        }
        break;
    }
}
/* localdecomp:end func_L02_00325E90 */
