/* functional: medium. Builds a ring of 5 network/effect message records (type 0x109D): collects the object index list for idx from the 16-bit list table D_L41_0028EB60 (stops after the entry with bit 15 set), then writes 5 records into message buffers from func_L39_0066C2B8/func_L39_0066C280 (the first at pos, the other four at pos + 2*(cos,sin) of an angle advancing pi/6 per record via func_0038DAB8), each carrying a2, a random-id pair, a5, a6 and the matching list entry; returns the five ids in out[] and registers them with func_L41_0053FB18(second_id, 5, ids). Written from the asm; the w component of records 2-5 is whatever the stack held in retail (uninitialised), set to 0 here. Compiles; shape differs. */
typedef int Q_003ED748 __attribute__((mode(TI)));

extern unsigned short *D_L41_0028EB60[];
extern int D_L41_00248698[];
extern unsigned char *D_L41_0024865C[];
extern int D_001A5DF8[];
extern int *func_L39_0066C2B8(void);
extern int func_L39_0066C280(int, int, int, int, void *);
extern int func_00197498(int);
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern float func_0038DAB8(float, float);
extern void func_L41_0053FB18(int, int, int *);

void func_L41_003ED748(Q_003ED748 *pos, int idx, int a2, int *out, int a4, int a5, int a6) {
    float pf[4] __attribute__((aligned(16)));
    float vx;
    float vy;
    float vz;
    int list[16];
    int ids[5];
    int *msg;
    unsigned char *rec;
    unsigned short *lp;
    unsigned char *base;
    int n;
    int cnt;
    int off;
    int first;
    int second;
    float ang;

    *(Q_003ED748 *)pf = *pos;
    msg = func_L39_0066C2B8();
    n = 0;
    lp = D_L41_0028EB60[idx];
    if ((idx & 0xFF) != 0xFF && D_L41_00248698[0] >= idx && lp != 0) {
        base = D_L41_0024865C[0];
        do {
            if (base + ((*lp & 0x7FFF) << 8) == 0) {
                break;
            }
            list[n++] = (int)((base + ((*lp & 0x7FFF) << 8)) - base) >> 8;
            lp++;
        } while ((short)lp[-1] >= 0);
    }
    if (msg == 0) {
        return;
    }
    ang = 3.1415927f;
    first = func_00197498(2);
    second = func_00197498(2);
    ids[0] = first;
    off = func_L39_0066C280(0, first, D_001A5DF8[0] + 0x1F4, 0x109D, msg);
    rec = (unsigned char *)msg + off;
    *(Q_003ED748 *)rec = *(Q_003ED748 *)pf;
    *(int *)(rec + 0x10) = a2;
    *(int *)(rec + 0x14) = second;
    *(int *)(rec + 0x18) = 0x539;
    *(int *)(rec + 0x1C) = 0;
    *(int *)(rec + 0x20) = a5;
    *(int *)(rec + 0x24) = a6;
    *(int *)(rec + 0x28) = list[0];
    msg[0] = off + 0x2C;
    out[0] = first;
    for (cnt = 1; cnt < 5; cnt++) {
        float c;
        float s;
        int id;

        c = func_0038D098(ang);
        vx = c + c;
        s = func_0038D0B0(ang);
        vy = s + s;
        vz = 0.0f;
        ang = func_0038DAB8(ang, 0.5235988f);
        vx = vx + pf[0];
        vy = vy + pf[1];
        vz = vz + pf[2];
        msg = func_L39_0066C2B8();
        if (msg == 0) {
            return;
        }
        id = func_00197498(2);
        off = func_L39_0066C280(0, id, D_001A5DF8[0] + 0x1F4, 0x109D, msg);
        rec = (unsigned char *)msg + off;
        *(float *)(rec + 0) = vx;
        *(float *)(rec + 4) = vy;
        *(float *)(rec + 8) = vz;
        *(float *)(rec + 0xC) = 0.0f;
        *(int *)(rec + 0x10) = a2;
        *(int *)(rec + 0x14) = second;
        *(int *)(rec + 0x18) = 0;
        *(int *)(rec + 0x1C) = 0;
        *(int *)(rec + 0x20) = a5;
        *(int *)(rec + 0x24) = a6;
        *(int *)(rec + 0x28) = list[cnt];
        out[cnt] = id;
        ids[cnt] = id;
        msg[0] = off + 0x2C;
    }
    func_L41_0053FB18(second, 5, ids);
}
