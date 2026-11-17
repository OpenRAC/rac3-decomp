#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00681130 */
void func_L39_00681330(void *);

void func_L39_00681130(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
    *(s32 *)((u8 *)arg0 + 0x68) = -1;
    func_L39_00681330(arg0);
}
/* localdecomp:end func_L39_00681130 */

/* localdecomp:start func_L39_00681158 */
__asm__(".extern D_L39_00247514, 16");
struct S_006814B0;
extern s32 *func_003B42F8(s32);
s32 func_003B4528(void *, s32, s32, s32, s32);
s32 func_003E8710(s32, s32);
s32 func_L01_00517190(s32, s32);
typedef struct S_00681158 {
    u8 pad0[0x4954];
    s32 f4954;
    u8 f4958[1];
} S_00681158;
typedef struct O_00681158 {
    u8 pad0[0x64];
    s32 ids[2];
    u8 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
} O_00681158;
extern s32 D_001DBE08_sda[2];
extern s32 D_001DBE00_sda;
extern s32 D_L39_00247514;
extern S_00681158 D_001F0A00;

void func_L39_00681158(struct S_006814B0 *arg0) {
    O_00681158 *p = (O_00681158 *)arg0;
    s32 *bufs;

    if (p->f70 >= 0) {
        return;
    }
    if (p->ids[p->f74] < 0) {
        return;
    }
    if (p->f6C) {
        if (D_001DBE08_sda[0] == 0 && ((void **)&D_L39_00247514)[2] == 0) {
            D_001DBE08_sda[0] = (s32)p;
            ((void **)&D_L39_00247514)[2] = p;
            func_003B4528((void *)func_003B42F8(0), D_001DBE00_sda, 0, D_001F0A00.f4954, (s32)D_001F0A00.f4958);
            func_003B4528((void *)func_003B42F8(1), D_L39_00247514, 0, D_001F0A00.f4954, (s32)D_001F0A00.f4958);
            func_003E8710(p->ids[0], (s32)func_003B42F8(0));
            func_003E8710(p->ids[1], (s32)func_003B42F8(1));
            func_L01_00517190(p->ids[p->f74], p->f7C + 1);
            p->f70 = 0;
        } else {
            p->f6C = 0;
        }
        if (p->f6C) {
            return;
        }
    }
    if (D_001DBE08_sda[0] == 0) {
        p->f70 = 0;
    } else if (((void **)&D_L39_00247514)[2] == 0) {
        p->f70 = 1;
    }
    if (p->f70 >= 0) {
        bufs = &D_001DBE00_sda;
        D_001DBE08_sda[p->f70] = (s32)p;
        func_003B4528((void *)func_003B42F8(p->f70), bufs[p->f70], 0, D_001F0A00.f4954, (s32)D_001F0A00.f4958);
        func_003E8710(p->ids[0], (s32)func_003B42F8(p->f70));
        func_L01_00517190(p->ids[0], p->f7C + 1);
    }
}
/* localdecomp:end func_L39_00681158 */

/* localdecomp:start func_L39_00681330 */
/* LOG func_L39_00681330 (best: 4 diff, branch 1 only: retail order is sw gp; sw 751c; b; li in delay slot,
   mine has sw gp in the delay slot and li before b; the else branch and both vtable calls match).
   - vt temp (vt = o->vtbl; vt->fn(o)) fixes lw v1,4(v0) before move a0,v0 in all three calls
   - tbl = D_001DBE08_sda after the call -> addiu s0,gp (else branch)
   - fn pointer of type s32 (*)(void *) (a void one gave idx in v0 and -1 in v1): else branch then matches
   - D_L39_0024751C needs __asm__(".extern .., 16") and NO section attribute to give lui $at
   - -1 stored in both arms (a single store after the if/else gives 25 diff)
   - all 6 orders of the three stores in arm 1 tried: only (751c, sda, -1) is crossjumped into the shared sw
   - vperm: VM slots stayed busy; one run on an earlier draft only found the fn-temp idea */
__asm__(".extern D_L39_00247514, 16");
typedef struct V_00681330 {
    u8 pad[0xC];
    s32 (*fn)(void *);
} V_00681330;
typedef struct S_00681330 {
    u8 pad[4];
    V_00681330 *vtbl;
} S_00681330;
extern s32 *func_003B42F8(s32);
extern s32 D_001DBE08_sda[2];
extern s32 D_L39_00247514;
void func_L39_00681330(void *arg0) {
    s32 (*fn)(void *);
    S_00681330 *o;
    V_00681330 *vt;
    s32 *tbl;
    if (*(s32 *)((u8 *)arg0 + 0x70) >= 0) {
        if (*(u8 *)((u8 *)arg0 + 0x6C) != 0) {
            o = (S_00681330 *)func_003B42F8(0);
            vt = o->vtbl;
            vt->fn(o);
            o = (S_00681330 *)func_003B42F8(1);
            vt = o->vtbl;
            fn = vt->fn;
            fn(o);
            D_001DBE08_sda[0] = 0;
            ((s32 *)&D_L39_00247514)[2] = 0;
            *(s32 *)((u8 *)arg0 + 0x70) = -1;
        } else {
            o = (S_00681330 *)func_003B42F8(*(s32 *)((u8 *)arg0 + 0x70));
            tbl = D_001DBE08_sda;
            vt = o->vtbl;
            fn = vt->fn;
            fn(o);
            tbl[*(s32 *)((u8 *)arg0 + 0x70)] = 0;
            *(s32 *)((u8 *)arg0 + 0x70) = -1;
        }
    }
}
/* localdecomp:end func_L39_00681330 */

/* localdecomp:start func_L39_006813F8 */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_00247514, 16");
__asm__(".extern D_L39_0024CAD8, 16");
extern s32 D_L39_0025F680[];
extern s32 D_L39_0024B9C8;
extern s32 D_L39_00247514;
extern s32 D_L39_0024CAD8;
extern s32 D_001DBE00_sda;
extern s32 D_001DBE10_sda;
void func_003A92F0(s32);
void func_003A9108(void);
s32 func_00139E08(s32);

void func_L39_006813F8(void) {
    func_003A92F0(1);
    func_00139E08(0);
    D_L39_0024B9C8++;
    D_001DBE00_sda = D_L39_0025F680[3] + 0x80000;
    D_L39_00247514 = D_001DBE00_sda + 0x40000;
    D_001DBE10_sda = D_L39_0025F680[4] + 0x80000;
    D_L39_0024CAD8 = 0x80000;
    func_003A9108();
}
/* localdecomp:end func_L39_006813F8 */

/* localdecomp:start func_L39_00681470 */
extern s32 D_001DBE00_sda;
extern s32 D_001DBE10_sda;
extern s32 D_L39_00247514 __attribute__((section(".data")));
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_L39_005FCC58(void);

void func_L39_00681470(void) {
    D_001DBE00_sda = 0;
    D_L39_00247514 = 0;
    D_001DBE10_sda = 0;
    func_003A92F0(1);
    func_L39_005FCC58();
    func_003A9108();
}
/* localdecomp:end func_L39_00681470 */

/* localdecomp:start func_L39_006814B0 */
typedef struct S_006814B0 {
    u8 pad[0x64];
    s32 ids[2];
    u8 f6C;
    u8 pad2[5];
    s32 f74;
    u8 f78;
    u8 pad3[3];
    s32 f7C;
} S_006814B0;

extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L39_00681158(S_006814B0 *);
extern s32 func_L01_00517190(s32, s32);

s32 func_L39_006814B0(S_006814B0 *self, s32 arg1) {
    if (self->f7C == arg1) {
        return 1;
    }
    if (self->ids[0] == -1) {
        return 0;
    }
    if (self->ids[1] == -1) {
        return 0;
    }
    self->f7C = arg1;
    if (self->f6C != 0) {
        if (self->f78 == 0) {
            self->f78 = 1;
            self->f74 = (self->f74 + 1) % 2;
        }
    }
    if (self->ids[0] >= 0) {
        func_L01_00516AA0(self->ids[0], 0x8000, self->f6C ^ 1);
    }
    if (self->ids[1] >= 0) {
        func_L01_00516AA0(self->ids[1], 0x8000, self->f6C ^ 1);
    }
    func_L39_00681158(self);
    return func_L01_00517190(self->ids[self->f74], self->f7C + 1);
}
/* localdecomp:end func_L39_006814B0 */

/* localdecomp:start func_L39_00681598 */
s32 func_L01_005170B8(s32, s32);

s32 func_L39_00681598(void *arg0, s32 arg1) {
    s32 *p;
    s32 *base;

    base = (s32 *)((u8 *)arg0 + 0x64);
    p = base + *(s32 *)((u8 *)arg0 + 0x74);
    if (*p == -1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    return func_L01_005170B8(*p, arg1);
}
/* localdecomp:end func_L39_00681598 */

/* localdecomp:start func_L39_006815F0 */
typedef struct S_006815F0 S_006815F0;
typedef struct V_006815F0 {
    u8 pad[0x30];
    void (*get)(S_006815F0 *, f32 *, f32 *);
} V_006815F0;
struct S_006815F0 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x50];
    f32 f58;
    f32 f5C;
    V_006815F0 *vt;
    s32 ids[2];
    u8 f6C;
    u8 pad2[7];
    s32 f74;
    u8 f78;
    u8 pad3[7];
    s32 f80;
};

extern s32 *func_003B42F8(s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);

void func_L39_006815F0(S_006815F0 *self) {
    f32 x, y;

    if (self->ids[0] == -1) {
        return;
    }
    if (self->f78 != 0 && self->f6C != 0 && (*func_003B42F8(self->f74) ^ 2) == 0) {
        func_L01_005170B8(self->ids[self->f74], self->f80);
        func_L01_005170B8(self->ids[(self->f74 + 1) % 2], 0);
        self->f78 = 0;
    }
    if (self->f4 == 0) {
        func_L01_00516AA0(self->ids[0], 1, 0);
        func_L01_00516AA0(self->ids[1], 1, 0);
    } else {
        func_L01_00516AA0(self->ids[0], 1, 1);
        func_L01_00516AA0(self->ids[1], 1, 1);
        self->vt->get(self, &x, &y);
        func_L01_00516470(self->ids[0], x, y);
        func_L01_00516470(self->ids[1], x, y);
        func_L01_00517538(self->ids[0], self->f58, self->f5C);
        func_L01_00517538(self->ids[1], self->f58, self->f5C);
    }
}
/* localdecomp:end func_L39_006815F0 */

