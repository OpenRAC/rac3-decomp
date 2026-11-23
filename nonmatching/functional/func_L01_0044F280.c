/* functional: high. VU0 vadd.xyzw rewritten as plain 4-float adds (all four components, w included, as retail). 60 diff lines are VU0 vs scalar only */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_44F280;
extern void func_0038D000(void *, void *, void *);

void func_L01_0044F280(Vec_44F280 *dst, u8 *obj, Vec_44F280 *offset, void *mat, void *other) {
    Vec_44F280 temp;
    Vec_44F280 *q;
    func_0038D000(&temp, obj + 0x30, mat);
    dst->x = offset->x + temp.x;
    dst->y = offset->y + temp.y;
    dst->z = offset->z + temp.z;
    dst->w = offset->w + temp.w;
    if (*(u8 **)(obj + 0x40)) {
        switch (obj[0x4C] & 0x30) {
        case 0x10:
            func_0038D000(&temp, *(u8 **)(obj + 0x40) + 0x10, mat);
            q = &temp;
            break;
        case 0x20:
            func_0038D000(&temp, *(u8 **)(obj + 0x40) + 0x10, other);
            q = &temp;
            break;
        default:
            q = (Vec_44F280 *)(*(u8 **)(obj + 0x40) + 0x10);
            break;
        }
        dst->x = dst->x + q->x;
        dst->y = dst->y + q->y;
        dst->z = dst->z + q->z;
        dst->w = dst->w + q->w;
    }
}
