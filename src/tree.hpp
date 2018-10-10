#pragma once

#include <array>
#include <cassert>

// Represents any kind of expression in the programming language. 
// The type T represents the type of expression
template<typename T, int N>
class Tree 
{
public:
    Tree();
    /// Constructs a nullary expression.

    Tree(T* e);
    /// Constructs a unary expression.

    Tree(T* e1, T* e2);
    /// Constructs a binary expression.

    Tree(T* e1, T* e2, T* e3);
    /// Constructs a ternary expression.
    
    // Accessors

    static constexpr int get_arity() { return N; }
    /// Returns the arity of the expression.

    T* get_child(int n) const;
    /// Returns the nth operand.

    T* get_child() const;
    /// Returns the sole operand. This is valid only when N == 1.

    // Iteration

    T** begin() { return m_ops.data(); }
    /// Returns an iterator pointing to the first operand.
    
    T** end() { return m_ops.data() + m_ops.size(); }
    /// Returns an iterator pointing past the last operand.

    T* const* begin() const { return m_ops.data(); }
    /// Returns an iterator pointing to the first operand.
    
    T* const* end() const { return m_ops.data() + m_ops.size(); }
    /// Returns an iterator pointing past the last operand.

private:
    std::array<T*, N> m_ops;
    /// An array containing the expression's operands.
};

template <typename T, int N>
inline
Tree<T, N>::Tree()
    : m_ops()
{
    assert(N == 0);
}

template <typename T, int N>
inline
Tree<T, N>::Tree(T* e1)
    : m_ops {e1}
{
    assert(N == 1);
}

template <typename T, int N>
inline
Tree<T, N>::Tree(T* e1, T* e2)
    : m_ops {e1, e2}
{
    assert(N == 2);
}

template <typename T, int N>
inline
Tree<T, N>::Tree(T* e1, T* e2, T* e3)
    : m_ops {e1, e2, e3}
{
    assert(N == 2);
}

template<typename T, int N>
inline T*
Tree<T, N>::get_child(int n) const
{
    assert(0 <= n && n < N);
    return m_ops[n];
}

template<typename T, int N>
inline T*
Tree<T, N>::get_child() const
{
    static_assert(N == 1);
    return m_ops[0];
}
