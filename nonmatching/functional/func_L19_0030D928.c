/* functional: high. Rewritten without COP2: two vector adds done as plain float x,y,z adds with w copied; retail is byte-exact only with a per-file -mvu0-use-vf0-vf2 flag the file lacks. */
typedef struct { f32 x, y, z, w; } Vec_0030D928;
extern f32 D_001DC610_sda;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L19_0030D928(u8 *obj, void *dst1, void *dst2) {
    Vec_0030D928 v0, v10;
    Vec_0030D928 *o = (Vec_0030D928 *)(obj + 0x10);
    Vec_0030D928 *d1 = (Vec_0030D928 *)dst1;
    Vec_0030D928 *d2 = (Vec_0030D928 *)dst2;

    func_0038CF68(&v0, obj + 0xC0, D_001DC610_sda);
    func_0038CE20(&v10, &v0, -1.0f);
    d1->x = v0.x + o->x;
    d1->y = v0.y + o->y;
    d1->z = v0.z + o->z;
    d1->w = v0.w;
    d2->x = v10.x + o->x;
    d2->y = v10.y + o->y;
    d2->z = v10.z + o->z;
    d2->w = v10.w;
}
