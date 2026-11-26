#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} G391938A;
typedef struct {
    u8 pad0[336];
    s16 unk150;
    s16 unk152;
} G391938B;
typedef struct {
    u8 pad0[36];
    s32 unk24;
} V391938;
typedef struct {
    u8 pad0[104];
    V391938 *pVars;
} M391938;
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} V_003919E0;
typedef struct { u8 pad0[48]; s32 id; u8 pad1[28]; } Ent_00312A80;
typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258;

/* declared by earlier blocks of L01_0038EB80.c, which this file was cut from */
extern u8 D_L01_002C5600[];
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];

/* localdecomp:start func_L01_003916E8 */
#include "vu0.h"
typedef struct { u8 pad[0x1200]; u8 *object; u8 pad1204[0x24]; s32 index; } Hero_003916E8;
typedef struct { u8 pad; u8 type; u8 rest[0xEE]; } Entry_003916E8;
extern f32 D_L01_001DDFEC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDFEC, 4");
extern f32 D_L01_001DDFF0 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DDFF0, 4");
void func_L01_003916E8(void) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, f32, f32, f32, s32);
    vu0_v4 zero, origin, pos;
    s32 type = ((Entry_003916E8 *)(D_001425C0[((Hero_003916E8 *)D_001A4BE0)->index]*240 + (s32)D_L01_002C5600))->type;
    s32 color1, color2, i, alpha;
    f32 radius, azimuth;
    u8 *p;
    u8 *p2;
    qzero(&zero);
    if (type==1) { color1=0x7F2020; color2=0xFF4040; }
    else if (type==2) { color1=0x20207F; color2=0x4040FF; }
    else if (type==3) { color1=0x20407F; color2=0x4080FF; }
    else { color1=0x20207F; color2=0x4040FF; }
    *(vu0_q *)&origin = *(vu0_q *)(((Hero_003916E8 *)D_001A4BE0)->object + 0x10);
    for (i=0; i<5; i++) {
        radius=func_003824E0(0.01f,0.8f);
        azimuth=func_00382538();
        func_00382760(&pos,radius,azimuth,func_003824E0(0.0f,3.1415927f));
        vec_add_ab(&pos, &pos, &origin);
        alpha=func_00382498(0,111);
        p=func_L01_0046B458(&pos,(func_00382498(12,20)*5+2)/6,color1|(alpha<<24),0,1,&zero,D_L01_001DDFEC*0.5f,D_L01_001DDFEC,0.0f,0);
        if (p) p[9]=0x74;
        p2=func_L01_0046B458(&pos,(func_00382498(12,20)*5+2)/6,color2|(alpha<<24),1,1,&zero,D_L01_001DDFF0*0.5f,D_L01_001DDFF0,0.0f,0);
        if (p2) p2[9]=0x74;
    }
}
/* localdecomp:end func_L01_003916E8 */

/* localdecomp:start func_L01_00391938 */
#include "vu0.h"
typedef struct { vu0_q direction; f32 angle, speed; s32 life; void *owner; f32 scale; u8 pad[12]; } Particle_00391938;
extern Particle_00391938 D_L01_0029EFA0[];
void func_L01_00391938(u8 *m) {
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    vu0_v4 forward, position, end;
    vu0_v4 *pos = &position;
    u8 *v = *(u8 **)(m+0x68);
    Particle_00391938 *p;
    p=D_L01_0029EFA0;
    do {
        if(p->owner == 0) {
            p->owner=m;
            p->angle=func_00382538();
            p->speed=func_L01_00443A18(1200.0f,1400.0f)*0.017453292f*0.020000001f;
            p->life=31;
            p->scale=func_003824E0(0.3f,0.4f);
            func_0038CF68(&forward,*(u8 **)(v+0x18)+0xD0,1.0f);
            *(vu0_q *)&position=*(vu0_q *)(m+0x10);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(position), "m"(forward) : "vf1", "vf2");
            func_0038CE90((f32 *)pos,(f32 *)pos,(f32 *)&end);
            func_0038CF68(p,pos,p->scale);
            break;
        }
        p++;
    } while ((s32)p < (s32)(D_L01_0029EFA0+12));
}
/* localdecomp:end func_L01_00391938 */

/* localdecomp:start func_L01_00391A80 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern void func_L01_00391BD0_00391A80(u8 *, vu0_v4 *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);

void func_L01_00391A80(u8 *m) {
    vu0_v4 forward, pos;
    u8 *v = *(u8 **)(m + 0x68);
    Particle_00391938 *p;
    f32 t;
    s32 i;

    for (i = 0; i < 12; i++) {
        p = &D_L01_0029EFA0[i];
        if (p->owner == m) {
            func_0038CF68(&forward, *(u8 **)(v + 0x18) + 0xD0, 1.0f);
            t = p->life / 37.0f;
            func_0038D890((f32 *)&pos, (f32 *)p, (f32 *)&forward, p->angle);
            func_L01_00391BD0_00391A80(m, &pos, t * 128.0f);
            p->angle = func_0038DAB8(p->angle, p->speed);
            func_0038CF68(&forward, &forward, 0.04f);
            vec_add_ab(p, p, &forward);
            if (func_0038CAD0(&D_L01_0029EFA0[i].life)) {
                p->owner = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_00391A80 */

/* localdecomp:start func_L01_00391BD0 */
#include "vu0.h"
typedef int Q_00391BD0 __attribute__((mode(TI)));
typedef struct {
    Q_00391BD0 pos, vel;
    f32 f20, f24, f28, f2C;
    s32 f30, f34, color, life, start;
    u8 *owner;
    s32 f48, f4C;
} Effect_00391BD0;
extern Effect_00391BD0 D_L01_0029F1E0[];
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
void func_L01_00391BD0(u8 *obj, Q_00391BD0 *pos, s32 kind)
{
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    s32 *vars = *(s32 **)(obj + 0x68);
    u8 *base = (u8 *)D_L01_0029F1E0;
    u8 *hero = D_001A4BE0;
    u8 *map = D_001425C0;
    u8 *weapons = D_L01_002C5600;
    s32 i;
    Effect_00391BD0 *p;
    for (i = 0; i < 128; ++i) {
        p = (Effect_00391BD0 *)(i * 80 + base);
        if (p->owner == 0) {
            p->owner = obj;
            p->f30 = kind;
            p->pos = *pos;
            qzero(&p->vel);
            {
                u8 type = weapons[*(u8 *)(*(s32 *)(hero + 0x1228) + (s32)map) * 240 + 1];
                if (type == 1) p->color = 0x601010;
                else if (type == 2) p->color = 0x204060;
                else if (type == 3) p->color = 0x101060;
                else p->color = 0x601010;
            }
            p->f20 = func_003824E0(0.1f, 0.2f);
            p->f24 = func_003824E0(0.3f, 0.4f);
            p->life = (func_00382498(25, 40) * 5 + 2) / 6;
            p->start = p->life;
            p->f2C = func_00382538();
            p->f28 = func_L01_00443A18(180.0f, 360.0f) * 0.017453292f * 0.020000001f;
            ++*vars;
            break;
        }
    }
}
/* localdecomp:end func_L01_00391BD0 */

/* localdecomp:start func_L01_00391D88 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CF68(void *out, void *in, f32 length);
extern void func_0038CE20(f32 *, f32 *, f32);
extern s32 func_0038CAD0(void *);
void func_L01_00391D88(u8 *obj) {
    Effect_00391BD0 *r;
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 change;
    s32 i;
    for (i = 0; i < 128; i++) {
        r = &D_L01_0029F1E0[i];
        if (r->owner == obj) {
            r->f34 = (s32)((f32)r->f30 * ((f32)r->life / (f32)r->start));
            r->f2C = func_0038DAB8(r->f2C, r->f28);
            vec_add_ab(&r->pos, &r->pos, &r->vel);
            func_0038CF68(&change, *(u8 **)(vars + 0x18) + 0xD0, 1.0f);
            func_0038CE20((f32 *)&change, (f32 *)&change, -0.0009f);
            vec_add_ab(&r->vel, &r->vel, &change);
            if (func_0038CAD0(&r->life)) {
                if (r->f34 > 0) r->f34--;
                else {
                    r->owner = 0;
                    (*(s32 *)vars)--;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00391D88 */
