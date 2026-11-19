/* functional: high. Switch case order verified against the level-02 copy's jtbl; register allocation/stack differs only (loop var in different saved regs); 0.005/1.0 floats loaded from sdata vs immediate */
typedef struct {
    s32 id;
    s32 link;
    s32 type;
    s32 xC;
    f32 x10, x14, x18, x1C;
    s32 flags20;
    s32 x24;
    f32 x28;
    s32 flags2C;
} W_0049B8F8;
extern void func_L01_00518D40(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E8630(s32, s32);

void func_L01_0049B8F8(W_0049B8F8 *tbl) {
    s32 i, a, b, r;
    W_0049B8F8 *e;
    f32 s;

    i = 0;
    b = 3;
    a = 3;
    while (tbl[i].id != 0) {
        e = &tbl[i];
        switch (e->type) {
        case 0:
            func_L01_00518D40(e->id);
            if (e->flags2C & 1) {
                func_L01_00518590(e->id, 1, 1);
                func_L01_00516470(e->id, e->x10, e->x14);
                func_L01_00517538(e->id, e->x18, e->x1C);
            }
            break;
        case 1:
            func_003E8EF0(e->id, e->x24, e->xC, e->x10, e->x14, e->x18, e->x1C, 0.0f);
            break;
        case 2:
            func_003E9138(e->id, e->xC, e->x24, e->x10, e->x14, e->x18, e->x1C);
            break;
        case 3:
            s = e->x28;
            func_003E9270(e->id, e->xC, e->x10, e->x14, e->x18, e->x1C, s, s);
            break;
        case 4:
            r = e->x24;
            if (e->flags2C & 4) r = func_00381FF0(e->x24);
            func_003E90B8(e->id, r, e->xC, e->x10, e->x14, e->x18, e->x1C, 0.005f, 0.005f);
            break;
        case 5:
            r = e->x24;
            if (e->flags2C & 4) r = func_00381FF0(e->x24);
            func_003E9358(e->id, r, e->xC, e->x10, e->x14, e->x18, e->x1C, 1.0f);
            func_L01_00516818(e->id, e->x28);
            s = e->x28 * 0.005f;
            func_L01_00516728(e->id, s, s);
            func_L01_00516AA0(e->id, 0x40, 1);
            if (e->flags2C & 8) func_L01_00518670(e->id, 1, 1);
            break;
        default:
            break;
        }
        r = e->flags20;
        if (r != 0) {
            if (r & 1) a = 1;
            else if (r & 2) a = 2;
            if (r & 8) b = 1;
            else if (r & 0x10) b = 2;
            func_L01_00516B90(e->id, a, b);
        }
        if (e->flags2C & 2) func_L01_00516AA0(e->id, 1, 0);
        if (e->link != 0) func_003E8630(e->link, e->id);
        i++;
    }
}
