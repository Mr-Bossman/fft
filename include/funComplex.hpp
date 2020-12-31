#include "common.h"
class CompL{
    public:
    CompL();
    uint64_t imag();
    uint64_t real();
    void imag(const uint64_t& num);
    void real(const uint64_t& num);
    const CompL mult(const CompL& num) const;
    const CompL add(const CompL& num) const;
    const CompL div(const CompL& num) const;
    const CompL sub(const CompL& num) const;
    const CompL pow(const CompL& num) const;

    struct dat
    {
        uint64_t pR;
        uint64_t nR;
        uint64_t pI;
        uint64_t nI;
    }data;
};
