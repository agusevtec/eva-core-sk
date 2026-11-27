#pragma once

namespace eva 
{
    /**
     * @brief Simple stateful reader acting as a ground-level of proccessing pipe
     */
    class ValueReader
    {
    private:
        signed short mValue = 0;

    public:
        void setValue(signed short value) { mValue = value; }
        signed short getValue() const { return mValue; }
        bool isValid() const { return true; }
    };
}
