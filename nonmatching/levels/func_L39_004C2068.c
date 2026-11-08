/* Near miss, ported from rac4-decomp's func_L00_004FDE68 (cross-game near pair). NEAR: SQ_RA: frame 0x20/ra@0x10 vs 0x10; v0/v1 swap in inner-pointer loads goes with it; rest of body identical */
extern void func_L39_004BC6C8(int, int, int, int, int);
extern void *func_L39_004BEED8(unsigned int);
extern int func_L39_004C2118(void *, int);
typedef struct Inner { int pad[12]; int ready; void *value; } Inner;
typedef struct Outer { char pad[80]; Inner *inner; char pad2[188]; unsigned int size; int other; } Outer;

int func_L39_004C2068(Outer *p)
{
    void *value;
    unsigned int size;
    if (p->inner->ready == 0 && func_L39_004C2118(p, p->other) == 0) goto fail;
    if (p->inner->value) goto success;
    size = p->size;
    if (size - 1 > 0x8000) { p->size = 0x8001; size = 0x8001; }
    value = func_L39_004BEED8(size);
    if (!value) goto fail;
    p->inner->value = value;
success:
    return 1;
fail:
    func_L39_004BC6C8(20, 219, 33, 0, 0);
    return 0;
}
