/* functional: high. Same reads, writes and calls as retail; stack frame and candidate-list bookkeeping are plain C. 0x19E6-style decode is not present in this variant. Variant of func_L39_005BB950 that walks the NULL-terminated object list D_L39_00292C20 and optionally uses a ground-plane (up-vector) angle test. */
typedef struct Cand_005BAFA8 {
    u8 *obj;
    f32 score;
    struct Cand_005BAFA8 *next;
    struct Cand_005BAFA8 **prev;
    f32 pos[4];
} Cand_005BAFA8;

extern u8 *D_L39_00292C20[];
extern Cand_005BAFA8 D_L39_002943C0[];
extern s32 D_L39_002429BC;
extern s32 D_001D72AC_sda;

extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern f32 *func_00382348(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_005B8928(u8 *);
extern void func_L01_00439880(u8 *, s32 *, s32 *);
extern void func_L39_005BC330(void *, void *, s32);

u8 *func_L39_005BAFA8(f32 *org, f32 *dir, s32 *count, u8 **out, s32 max, u8 **excl, s32 flagB4, s32 *ids,
                      s16 req, s16 optC0, s16 reqC4, f32 aLim, f32 bLim, f32 maxDist, f32 aMin, f32 bMin) {
    f32 tmp[4];
    f32 pos[4];
    f32 d[4];
    f32 up[4];
    f32 h[4];
    f32 dH[4];
    f32 dirV[4];
    f32 dirH[4];
    f32 sc[4];
    s32 sp90[2];
    Cand_005BAFA8 *head;
    Cand_005BAFA8 *tail;
    Cand_005BAFA8 *e;
    Cand_005BAFA8 *p;
    u8 *best;
    u8 *obj;
    f32 *r;
    f32 heading, pitch, dist, w, angA, angB, score, thr, lim, f20, f21, dotA;
    s32 poolUsed, i, s18, s21, spDC, hid;

    head = 0;
    best = 0;
    poolUsed = 0;
    tail = 0;
    thr = 1000000.0f;
    *count = 0;

    if (aLim == 0.0f) {
        return 0;
    }
    if (bLim == 0.0f) {
        return 0;
    }
    if (maxDist == 0.0f) {
        return 0;
    }

    heading = func_0038D160(dir[0], dir[1]);
    pitch = func_0038D160(func_0038CED8(dir), dir[2]);

    i = 0;
    obj = D_L39_00292C20[0];
    if (obj != 0) {
        do {
            i++;
            if (req != 0) {
                if (obj[0x31] == 0) {
                    goto next;
                }
            }
            hid = *(s16 *)(obj + 0xAA);
            spDC = 0;
            if (hid == 0x1A90 || hid == 0x1ADE) {
                spDC = 1;
            }
            s18 = 0;
            s21 = func_L39_005B8928(obj);
            {
                u8 *o24 = *(u8 **)(obj + 0x24);
                if (o24 != 0 && o24[0x46] == 0x16 && (*(u16 *)(obj + 0x34) & 0x4000) && obj[0x31] != 0) {
                    func_L01_00439880(obj, &sp90[0], &sp90[1]);
                    if (sp90[1] > 0) {
                        s18 = 1;
                        spDC = 1;
                    }
                }
            }
            if (s21 != 0) {
                if (flagB4 == 0) {
                    goto next;
                }
            }
            if (s18 != 0) {
                if (reqC4 == 0) {
                    goto next;
                }
            }
            r = func_00382348(obj);
            if (r == 0 || (r[0] <= 0.0f && s21 == 0)) {
                if (s18 == 0) {
                    goto next;
                }
            }
            {
                u8 *o24 = *(u8 **)(obj + 0x24);
                if (!(o24 != 0 && o24[0x46] == 5)) {
                    if (s21 == 0) {
                        if (s18 == 0) {
                            goto next;
                        }
                    }
                }
            }
            if (excl != 0) {
                u8 **q = excl;
                while (*q != 0) {
                    if (*q == obj) {
                        goto next;
                    }
                    q++;
                }
            }
            if (ids != 0) {
                s32 id0 = ids[0];
                if (id0 != -1) {
                    s32 hh = *(s16 *)(obj + 0xAA);
                    s32 *q = ids;
                    s32 idx = 0;
                    if (hh != id0) {
                        for (;;) {
                            q++;
                            if (*q == -1) {
                                idx = -1;
                                break;
                            }
                            idx++;
                            if (hh == *q) {
                                break;
                            }
                        }
                    }
                    if (idx >= 0) {
                        goto next;
                    }
                }
            }
            {
                f32 *op = (f32 *)(obj + 0x10);
                pos[0] = op[0];
                pos[1] = op[1];
                pos[2] = op[2];
                pos[3] = op[3];
            }
            if (r != 0) {
                if (D_L39_002429BC != 0 || optC0 != 0) {
                    func_0038CE20(tmp, obj + 0xE0, r[4]);
                    pos[0] += tmp[0];
                    pos[1] += tmp[1];
                    pos[2] += tmp[2];
                } else {
                    pos[2] += r[4];
                }
            } else {
                f32 f0 = *(f32 *)(obj + 0xC);
                if (D_L39_002429BC != 0 || optC0 != 0) {
                    func_0038CE20(tmp, obj + 0xE0, f0 * 0.0009765625f);
                    pos[0] += tmp[0];
                    pos[1] += tmp[1];
                    pos[2] += tmp[2];
                } else {
                    pos[2] += f0 * 0.0009765625f;
                }
            }
            d[0] = pos[0] - org[0];
            d[1] = pos[1] - org[1];
            d[2] = pos[2] - org[2];
            d[3] = pos[3];
            dist = func_0038CEA8(d);
            if (maxDist < dist) {
                goto next;
            }
            if (dist < 0.1f) {
                goto next;
            }
            w = func_L01_004451D0(-2.0f, 0.0f, 1.0f, 0.0f, dist / maxDist);
            angA = 0.0f;
            angB = 0.0f;
            if (aLim < 3.1415927f || bLim < 3.1415927f) {
                if (D_001D72AC_sda == 0) {
                    angA = func_0038DBA0(func_0038D160(d[0], d[1]), heading);
                    lim = aLim;
                    if (0.0f < aMin) {
                        lim = aMin + (aLim - aMin) * w;
                    }
                    if (lim <= angA) {
                        goto next;
                    }
                    angB = func_0038DBA0(func_0038D160(func_0038CED8(d), d[2]), pitch);
                } else {
                    func_L39_005BC330(org, up, 1);
                    dotA = func_0038CE68(up, d);
                    func_0038CE20(h, up, dotA);
                    dH[0] = d[0] - h[0];
                    dH[1] = d[1] - h[1];
                    dH[2] = d[2] - h[2];
                    dH[3] = d[3];
                    dotA = func_0038CE68(up, dir);
                    func_0038CE20(dirV, up, dotA);
                    dirH[0] = dir[0] - dirV[0];
                    dirH[1] = dir[1] - dirV[1];
                    dirH[2] = dir[2] - dirV[2];
                    dirH[3] = dir[3];
                    angA = func_0038CE68(dirH, dH);
                    if (angA < 0.0f) {
                        goto next;
                    }
                    f21 = func_0038CEA8(dH);
                    if (f21 == 0.0f) {
                        goto next;
                    }
                    f20 = func_0038CEA8(dirH);
                    if (f20 == 0.0f) {
                        goto next;
                    }
                    angA = 1.5707964f - func_0038D0C8(angA / (f21 * f20));
                    lim = aLim;
                    if (0.0f < aMin) {
                        lim = aMin + (aLim - aMin) * w;
                    }
                    if (lim <= angA) {
                        goto next;
                    }
                    func_0038CE20(sc, dH, f20 / f21);
                    sc[0] += dirV[0];
                    sc[1] += dirV[1];
                    sc[2] += dirV[2];
                    f20 = func_0038CEA8(sc);
                    f20 = f20 * dist;
                    angB = 1.5707964f - func_0038D0C8(func_0038CE68(sc, d) / f20);
                }
                lim = bLim;
                if (0.0f < bMin) {
                    lim = bMin + (bLim - bMin) * w;
                }
                if (lim <= angB) {
                    goto next;
                }
            }
            score = angA * 3.0f + (angB * 0.2f) * dist + dist * 0.1f;
            if (s21 != 0 || spDC != 0) {
                score = score * (maxDist * 0.8f);
            }
            if (poolUsed < 32) {
                e = &D_L39_002943C0[poolUsed];
                poolUsed++;
            } else {
                e = tail;
                *e->prev = 0;
            }
            e->obj = obj;
            e->pos[0] = pos[0];
            e->pos[1] = pos[1];
            e->pos[2] = pos[2];
            e->pos[3] = pos[3];
            e->score = score;
            if (head == 0) {
                tail = e;
                head = e;
                e->prev = &head;
                e->next = 0;
            } else {
                p = head;
                for (;;) {
                    if (score < p->score) {
                        e->next = p;
                        e->prev = p->prev;
                        *p->prev = e;
                        p->prev = &e->next;
                        break;
                    }
                    p = p->next;
                    if (p == 0) {
                        e->next = 0;
                        tail->next = e;
                        e->prev = &tail->next;
                        tail = e;
                        break;
                    }
                }
            }
        next:
            obj = D_L39_00292C20[i];
        } while (obj != 0);
    }

    while (head != 0) {
        p = head;
        obj = p->obj;
        if (p->score < thr) {
            if (func_003D3CB0(org, p->pos, 0x12, obj, 0) != 0) {
                goto skip;
            }
            best = obj;
            thr = head->score;
        }
        if (out != 0) {
            if (*count < max) {
                out[*count] = obj;
                (*count)++;
            }
        }
    skip:
        head = head->next;
    }

    if (out != 0) {
        if (best != 0) {
            s32 idx = 0;
            if (max > 0 && out[0] != best) {
                u8 *first = out[0];
                idx = 1;
                while (idx < max) {
                    if (out[idx] == best) {
                        out[0] = best;
                        out[idx] = first;
                        break;
                    }
                    idx++;
                }
            }
            if (idx == max) {
                out[0] = best;
            }
        }
        if (*count < max) {
            out[*count] = 0;
        }
    }
    return best;
}
