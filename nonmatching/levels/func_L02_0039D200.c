/* Level 02 (Florana), PAL. 5 diff with check.py --target level_02. 5 differences in the first five instructions of the switch dispatch: retail `lbu $v0; addiu $a0,$v0,-1; sltiu $v1,$a0,6; beqz $v1; sll $v1,$a0,2`, this C `lbu $v1; addiu $v1,$v1,-1; sltiu $v0,$v1,6; ...`. A local copy, `switch (f20 - 1)`, casts, a `default:` label and local reordering all gave the same bytes. The rest matches, including the jump table (`jtbl_002BCC00`). Uses one `goto` into the shared tail. */
typedef struct {
    s32 f0;
    s16 f4;
    s16 f6;
    float f8;
    float fC;
    float v10[4];
    u8 pad20[0x54];
    float f74;
    u8 pad78[0x18];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
    s32 fA4;
} B_39D200;
typedef struct {
    u8 pad0[0x18];
    float f18;
    u8 pad1C[4];
    u8 f20;
    u8 pad21[0x47];
    B_39D200 *p68;
    u8 pad6C[0x44];
    u8 fB0;
    u8 padB1[0x43];
    float fF4;
} S_39D200;
typedef struct {
    u8 pad0[0xD0];
    u8 fD0;
    u8 padD1[0xB];
    S_39D200 *fDC;
} E_39D200;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[][16];
__asm__(".extern D_001BBC40, 16");
extern u8 D_001A4C60[];
extern s16 *D_L02_0021B460[];
extern u8 D_001A30B0[];
extern void func_L01_0044E850(void *a, void *b, int c, float x, float y);
extern void func_0039D680(S_39D200 *);
extern s32 func_L01_00456500(void *, s32);
extern void func_003C5D60(s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern float func_003C3BE8(float, float, float);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_00382380(void *, s32, s32);

void func_L02_0039D200(S_39D200 *self) {
    B_39D200 *p = self->p68;
    float one, t, a;
    E_39D200 *e;
    s32 i;
    func_L02_0039D680(self);
    switch (self->f20) {
    case 1:
        if (p->f0 == -1) break;
        if (func_L01_00456500(D_001A4C60, p->f0) == 0) break;
        if (p->fA4 != 0 && (D_001BBC40[D_001D545C_sda][self->fB0] & 0x80)) break;
        if (p->fA0 != -1) func_003C5D60(p->fA0);
        self->f20 = 3;
        p->f74 = 0;
        p->f4 = 100;
        one = 1.0f;
        t = p->f74;
        func_L01_0044E850(self, p->v10, 0, one, t);
        break;
    case 2:
        if (p->f0 != -1 && func_L01_00456500(D_001A4C60, p->f0) != 0) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 100;
            one = 1.0f;
            t = p->f74;
            func_L01_0044E850(self, p->v10, 0, one, t);
        }
        if (p->f98 != 0xFF && D_L02_0021B460[p->f98] != 0) {
            if (func_L01_00445AD0(p->f98, -1, 0) == 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 100;
                one = 1.0f;
                t = p->f74;
                func_L01_0044E850(self, p->v10, 0, one, t);
            } else {
                if (D_001BBC40[D_001D545C_sda][self->fB0] & 0x80) {
                    self->f20 = 4;
                    p->f74 = 0;
                    p->f4 = 100;
                    one = 1.0f;
                    t = p->f74;
                    func_L01_0044E850(self, p->v10, 0, one, t);
                }
                break;
            }
        }
        if (D_001BBC40[D_001D545C][self->fB0] & 0x80) {
            self->f20 = 4;
            p->f74 = 0;
            p->f4 = 100;
            one = 1.0f;
            t = p->f74;
            func_L01_0044E850(self, p->v10, 0, one, t);
        }
        break;
    case 3:
        if (func_0038CB00(&p->f4)) {
            self->f20 = 6;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003C3BE8(6.2831855f, 0.0f, a);
            func_L01_0044E850(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003C3BE8(-1.5707964f, 0.0f, a);
            self->f18 = func_003C3BE8(p->fC + 10.0f, p->fC, a);
        } else {
            self->fF4 = func_003C3BE8(1.5707964f, 0.0f, a);
        }
        goto tail;
    case 4:
        if (func_0038CB00(&p->f4)) {
            self->f20 = 5;
            break;
        }
        a = (float)p->f4 * p->f8;
        if (p->f90 != 0) {
            p->f74 = func_003C3BE8(0.0f, 6.2831855f, a);
            func_L01_0044E850(self, p->v10, 0, 1.0f, 0.0f);
            self->fF4 = func_003C3BE8(0.0f, -1.5707964f, a);
            self->f18 = func_003C3BE8(p->fC, p->fC + 10.0f, a);
        } else {
            self->fF4 = func_003C3BE8(0.0f, 1.5707964f, a);
        }
    tail:
        if (func_L01_004AA710(self, p->f94) == 0) {
            p->f94 = func_003A52A0(0, 4, self);
        }
        break;
    case 5:
    case 6:
        p->f74 = 0;
        one = 1.0f;
        t = p->f74;
        func_L01_0044E850(self, p->v10, 0, one, t);
        i = p->f94;
        if (i != -1) {
            e = (E_39D200 *)&D_001A30B0[i << 7];
            if (e->fDC == self && e->fD0 != 0) func_003A4F28(i);
        }
        p->f94 = -1;
        if (self->f20 == 6) {
            if (func_00382380(D_001A4C60, p->f9C, 0) != 0) {
                self->f20 = 4;
                p->f74 = 0;
                p->f4 = 100;
                one = 1.0f;
                t = p->f74;
                func_L01_0044E850(self, p->v10, 0, one, t);
            }
        }
        break;
    }
}
