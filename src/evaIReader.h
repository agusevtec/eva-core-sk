#ifndef EVAIREADER_H
#define EVAIREADER_H

#pragma once

namespace eva
{
    /**
     * @brief Interface for value readers.
     *
     * The library uses templates internally for maximum performance and flexibility,
     * and never uses interfaces internally.
     * However, forcing users to write template code everywhere can be cumbersome.
     * All readers can be converted to this interface using the companion IReaderAdapter
     * for further use in polymorphic contexts.
     *
     * This two-tier approach gives us benefits:
     * -# Use templates directly for maximum performance
     * -# Use this interface for simpler integration and loose coupling
     *
     * @see IReaderAdapter
     */
    class IReader
    {
    public:
        virtual signed short getValue() = 0;
    };

    /**
     * @brief Adapter that converts any class with getValue() into an IReader.
     *
     * This adapter serves as a bridge between the template-based library core
     * and the interface-based library boundary. It allows:
     * -# Using template-based readers polymorphically
     * -# Passing library readers to functions expecting IReader*
     * -# Users to work with interfaces instead of templates when preferred
     *
     * @tparam T Class that implements getValue() (typically a reader decorator
     *           or a user-defined reader)
     *
     * @note This adapter incurs a virtual call overhead, so use it at API boundaries,
     *       not in performance-critical internal loops where templates are preferred.
     */
    template <class T>
    class IReaderAdapter : public IReader, public T
    {
    public:
        virtual signed short getValue() override
        {
            return T::getValue();
        }
    };
};

#endif
