/* functional: high. Allocates a 74-byte effect object, fills its header, position and a velocity sub-record; when a parent is given, rotates the offset into the parent's frame via the parent's matrix. */
extern u8 *D_L01_002211C0;
extern s32 func_0013D3E0(void);
extern void func_0038D5B0(void *dst, void *src);
extern void func_0038D028(void *dst, void *src, void *m);

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 *parent;
    f32 fvx;
    f32 fvy;
    f32 fvz;
    u8 *cfg;
} Sub_46E078;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    u16 hA;
    s32 wC;
    vu0_v4 pos;
    Sub_46E078 sub;
} Obj_46E078;

Obj_46E078 *func_L01_0046E078(u8 *parent, vu0_v4 *pos, f32 *vel, u8 *cfg, s32 flag) {
    Obj_46E078 *p = (Obj_46E078 *)((u8 *(*)(s32))func_L01_004618E0)(74);
    Sub_46E078 *q;
    vu0_v4 v;
    f32 m[16];
    if (p != 0) {
        p->b9 = 0xA0;
        p->b3 = (flag != 0) ? 0x48 : 0x44;
        p->b1 = 0;
        q = &p->sub;
        p->b2 = *D_L01_002211C0;
        p->b8 = func_0013D3E0();
        p->wC = 0;
        p->pos = *pos;
        q->f0 = vel[0];
        q->f4 = vel[1];
        q->f8 = vel[2];
        if (parent != 0) {
            vec_sub_ba(&v, pos, parent + 0x10);
            m[4] = m[5] = m[6] = m[7] = 0.0f;
            m[8] = m[9] = m[10] = m[11] = 0.0f;
            m[12] = m[13] = m[14] = m[15] = 0.0f;
            m[0] = m[1] = m[2] = m[3] = 0.0f;
            func_0038D5B0(&m[4], parent + 0xC0);
            func_0038D028(&v, &v, &m[4]);
            q->fvx = v.x;
            q->fvy = v.y;
            q->fvz = v.z;
        }
        q->parent = parent;
        q->cfg = cfg;
        p->hA = *(u16 *)(cfg + 0xC);
        p->w4 = *(s32 *)cfg;
    }
    return p;
}
