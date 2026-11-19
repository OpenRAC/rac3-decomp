/* functional: high. Searches a 15-entry table of (slotA, slotB, group) records for the first record whose referenced object (owner differs from self) lies within radius of obj, then calls func_L40_0053E000(radius,self,obj,group); for slotA records keeps looking when the result is -1 or 0, for slotB-only records returns its result at once; returns -1 when no record qualifies or the first empty record is hit. Compiles; loop shape and registers differ. */
typedef struct Rec_0053DE38 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad9[3];
} Rec_0053DE38;

typedef struct G_0053DE38 {
    unsigned char pad0[0x20C];
    unsigned char *p20C;
} G_0053DE38;

extern Rec_0053DE38 D_L40_00347AB0[];
extern G_0053DE38 D_L40_00357260;
extern unsigned char *D_L40_0024845C[];
extern float func_L01_0040E548(void *, void *);
extern int func_L40_0053E000(float, int, unsigned char *, unsigned char);

int func_L40_0053DE38(int self, unsigned char *obj, float radius) {
    Rec_0053DE38 *r;
    unsigned char *p;
    int ret;
    int k;

    for (k = 0; k < 15; k++) {
        r = &D_L40_00347AB0[k];
        if (r->a == -1 && r->b == -1) {
            return -1;
        }
        if (r->a != -1) {
            p = D_L40_00357260.p20C + r->a * 4;
            if (*(int *)(p + 0x88) != self) {
                if (func_L01_0040E548(obj + 0x10, D_L40_0024845C[0] + (*(int *)(p + 0x40) << 8) + 0x10) < radius) {
                    ret = func_L40_0053E000(radius, self, obj, r->c);
                    if (ret != -1 && ret != 0) {
                        return ret;
                    }
                }
            }
        } else if (r->b != -1) {
            p = D_L40_00357260.p20C + r->b * 4;
            if (*(int *)(p + 0xA8) != self) {
                if (func_L01_0040E548(obj + 0x10, D_L40_0024845C[0] + (*(int *)(p + 0x60) << 8) + 0x10) < radius) {
                    return func_L40_0053E000(radius, self, obj, r->c);
                }
            }
        }
    }
    return -1;
}
