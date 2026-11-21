/* functional: high. rewritten from the draft with clearer types; asm checked: tbl=D_1DA938, callee args, vtable slot 0xC called with (obj, self->0x2C), self->8 vtable pointers swapped, delete via func_003F2738 when flags&1. Codegen differs only. */
typedef struct { u8 pad0[0x4]; s32 f4; } S_003F0C98;
typedef struct { u8 p0[0xC]; s32 (*f0C)(void *, s32); } VT_003F0C98;
typedef struct { VT_003F0C98 *vt; } Obj_003F0C98;
typedef struct { u8 p0[8]; void *f8; u8 pC[0x20]; s32 f2C; } Dtor_003F0C98;
extern S_003F0C98 D_001DA938[];
extern u8 D_001D97C8[];
extern u8 D_001D9670[];
extern S_003F0C98 *func_003E6FC0(S_003F0C98 *);
extern Obj_003F0C98 *func_003E7078(S_003F0C98 *, s32);
extern void func_003F2738(void *);
void func_003F0C98(Dtor_003F0C98 *self, s32 flags) {
    S_003F0C98 *tbl;
    Obj_003F0C98 *o;
    self->f8 = D_001D97C8;
    tbl = D_001DA938;
    if (tbl->f4 == 0) tbl = func_003E6FC0(tbl);
    o = func_003E7078(tbl, 1);
    if (o != 0) {
        o->vt->f0C(o, self->f2C);
        self->f2C = 0;
    }
    self->f8 = D_001D9670;
    if (flags & 1) func_003F2738(self);
}
