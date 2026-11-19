/* functional: medium. Compiles at level_01 (114 diff, frame size 0x30 matches). The switch's jump table (jtbl_002BCC00) is not in the dumped asm for level 01; cases 0..5 are assumed to be the six code blocks in ascending order, as in level 02's copy of this function whose table (jtbl_002BA810) is six ascending distinct targets. Struct layout Widget_49A010 (0x30 bytes) read from offsets. */
typedef struct {
    s32 id;
    s32 parent;
    s32 kind;
    s32 color;
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    s32 align;
    s32 arg;
    f32 scale;
    s32 flags;
} Widget_49A010;
extern s32 func_L01_00518D40(s32);
extern void func_L01_00518590(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern void func_003E8630(s32, s32);

void func_L01_0049A010(Widget_49A010 *tbl) {
    s32 i = 0;
    s32 ha = 3;
    s32 va = 3;
    Widget_49A010 *e;
    s32 s;

    if (tbl[0].id == 0) {
        return;
    }
    do {
        e = &tbl[i];
        switch ((u32)e->kind) {
        case 0:
            func_L01_00518D40(e->id);
            if (e->flags & 1) {
                func_L01_00518590(e->id, 1, 1);
                func_L01_00516470(e->id, e->x, e->y);
                func_L01_00517538(e->id, e->w, e->h);
            }
            break;
        case 1:
            func_003E8EF0(e->id, e->arg, e->color, e->x, e->y, e->w, e->h, 0.0f);
            break;
        case 2:
            func_003E9138(e->id, e->color, e->arg, e->x, e->y, e->w, e->h);
            break;
        case 3:
            func_003E9270(e->id, e->color, e->x, e->y, e->w, e->h, e->scale, e->scale);
            break;
        case 4:
            s = e->arg;
            if (e->flags & 4) {
                s = func_00381FF0(e->arg);
            }
            func_003E90B8(e->id, s, e->color, e->x, e->y, e->w, e->h, 0.005f, 0.005f);
            break;
        case 5:
            s = e->arg;
            if (e->flags & 4) {
                s = func_00381FF0(e->arg);
            }
            func_003E9358(e->id, s, e->color, e->x, e->y, e->w, e->h, 1.0f);
            func_L01_00516818(e->id, e->scale);
            func_L01_00516728(e->id, e->scale * 0.005f, e->scale * 0.005f);
            func_L01_00516AA0(e->id, 0x40, 1);
            if (e->flags & 8) {
                func_L01_00518670(e->id, 1, 1);
            }
            break;
        default:
            break;
        }
        if (e->align != 0) {
            if (e->align & 1) {
                ha = 1;
            } else if (e->align & 2) {
                ha = 2;
            }
            if (e->align & 8) {
                va = 1;
            } else if (e->align & 0x10) {
                va = 2;
            }
            func_L01_00516B90(e->id, ha, va);
        }
        if (e->flags & 2) {
            func_L01_00516AA0(e->id, 1, 0);
        }
        if (e->parent != 0) {
            func_003E8630(e->parent, e->id);
        }
        i++;
    } while (tbl[i].id != 0);
}
