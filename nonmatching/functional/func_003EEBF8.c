/* functional: high. Written from PAL's assembly (no draft). The virtual call at vtable+0x20 receives retail's untouched $a1 (this function's second argument) explicitly, plus the rect and 1. Retail fills the 4-colour array via a 16-byte copy from a second stack array; here it is filled directly (same four words). */
typedef struct Widget_3EEBF8 Widget_3EEBF8;
typedef struct {
    u8 p0[0x20];
    void (*getRect)(Widget_3EEBF8 *, s32, f32 *, s32);   /* +0x20 */
} WidgetVt_3EEBF8;
struct Widget_3EEBF8 {
    u8 p0[8];
    WidgetVt_3EEBF8 *vt;    /* +0x08 */
    u8 pC[4];
    f32 maxX;               /* +0x10 */
    f32 maxY;               /* +0x14 */
    u8 p18[8];
    f32 shadowX;            /* +0x20 */
    f32 shadowY;            /* +0x24 */
    u32 shadowColor;        /* +0x28 */
    u8 p2C[4];
    u32 color;              /* +0x30 */
    f32 thickX;             /* +0x34 */
    f32 thickY;             /* +0x38 */
};
extern f32 D_001D9698;      /* screen x scale */
extern f32 D_001D969C;      /* screen y scale */
extern void func_003EE0A8(void *, f32 *);
extern void func_003E5C78(f32 *, f32, f32);
extern void func_0038C6F0_003EEBF8(s32, s32, s32, s32, s32, u32 *);

void func_003EEBF8(Widget_3EEBF8 *o, s32 arg1) {
    f32 r[4];
    u32 col[4];
    f32 a[3], b[3];
    f32 top, bottom;
    f32 dx, dy;

    o->vt->getRect(o, arg1, r, 1);
    func_003EE0A8(o, r);

    /* left edge */
    a[0] = r[1] + o->thickY;
    a[1] = r[0] + o->thickX;
    a[2] = r[3] - o->thickY;
    func_003E5C78(&a[0], r[1], o->maxY);
    func_003E5C78(&a[1], r[0], o->maxX);
    func_003E5C78(&a[2], o->maxY, r[3]);
    if (func_003EDEB0(o, 0x40)) {
        dx = o->shadowX;
        dy = o->shadowY;
        col[0] = col[1] = col[2] = col[3] = o->shadowColor;
        func_0038C6F0_003EEBF8((s32)((r[0] + dx) * D_001D9698), (s32)((a[0] + dy) * D_001D969C),
                               (s32)((a[1] + dx) * D_001D9698), (s32)((a[2] + dy) * D_001D969C), 0, col);
    }
    col[0] = col[1] = col[2] = col[3] = o->color;
    func_0038C6F0_003EEBF8((s32)(r[0] * D_001D9698), (s32)(a[0] * D_001D969C),
                           (s32)(a[1] * D_001D9698), (s32)(a[2] * D_001D969C), 0, col);

    /* right edge */
    b[0] = r[1] + o->thickY;
    b[1] = r[2] - o->thickX;
    b[2] = r[3] - o->thickY;
    func_003E5C78(&b[0], r[1], o->maxY);
    func_003E5C78(&b[1], o->maxX, r[2]);
    func_003E5C78(&b[2], o->maxY, r[3]);
    if (func_003EDEB0(o, 0x40)) {
        dx = o->shadowX;
        dy = o->shadowY;
        col[0] = col[1] = col[2] = col[3] = o->shadowColor;
        func_0038C6F0_003EEBF8((s32)((b[1] + dx) * D_001D9698), (s32)((b[0] + dy) * D_001D969C),
                               (s32)((r[2] + dx) * D_001D9698), (s32)((b[2] + dy) * D_001D969C), 0, col);
    }
    col[0] = col[1] = col[2] = col[3] = o->color;
    func_0038C6F0_003EEBF8((s32)(b[1] * D_001D9698), (s32)(b[0] * D_001D969C),
                           (s32)(r[2] * D_001D9698), (s32)(b[2] * D_001D969C), 0, col);

    /* top edge */
    top = r[1] + o->thickY;
    func_003E5C78(&top, r[1], o->maxY);
    if (func_003EDEB0(o, 0x40)) {
        dx = o->shadowX;
        dy = o->shadowY;
        col[0] = col[1] = col[2] = col[3] = o->shadowColor;
        func_0038C6F0_003EEBF8((s32)((r[0] + dx) * D_001D9698), (s32)((r[1] + dy) * D_001D969C),
                               (s32)((r[2] + dx) * D_001D9698), (s32)((top + dy) * D_001D969C), 0, col);
    }
    col[0] = col[1] = col[2] = col[3] = o->color;
    func_0038C6F0_003EEBF8((s32)(r[0] * D_001D9698), (s32)(r[1] * D_001D969C),
                           (s32)(r[2] * D_001D9698), (s32)(top * D_001D969C), 0, col);

    /* bottom edge */
    bottom = r[3] - o->thickY;
    func_003E5C78(&bottom, o->maxY, r[3]);
    if (func_003EDEB0(o, 0x40)) {
        dx = o->shadowX;
        dy = o->shadowY;
        col[0] = col[1] = col[2] = col[3] = o->shadowColor;
        func_0038C6F0_003EEBF8((s32)((r[0] + dx) * D_001D9698), (s32)((bottom + dy) * D_001D969C),
                               (s32)((r[2] + dx) * D_001D9698), (s32)((r[3] + dy) * D_001D969C), 0, col);
    }
    col[0] = col[1] = col[2] = col[3] = o->color;
    func_0038C6F0_003EEBF8((s32)(r[0] * D_001D9698), (s32)(bottom * D_001D969C),
                           (s32)(r[2] * D_001D9698), (s32)(r[3] * D_001D969C), 0, col);
}
