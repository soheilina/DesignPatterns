#ifndef __STRATEGY_HPP
#define __STRATEGY_HPP

#include "pch.hpp"

///////////////////////////////////////////////////////////////////////////////////////////
// Strategy interface
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T> class SortStrategy {
  public:
    SortStrategy() = default;
    virtual ~SortStrategy() = default;

  public:
    virtual std::vector<T> sort(std::vector<T> const& input) const = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////
// Concrete Strategies
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T> class StableSort final : public SortStrategy<T> {
  public:
    StableSort() = default;
    ~StableSort() = default;

  public:
    std::vector<T> sort(std::vector<T> const& input) const final {
        std::vector<T> tmp(input);
        std::stable_sort(tmp.begin(), tmp.end());
        return tmp;
    }
};

template <typename T> class UnstableSort final : public SortStrategy<T> {
  public:
    UnstableSort() = default;
    ~UnstableSort() = default;

  public:
    std::vector<T> sort(std::vector<T> const& input) const final {
        // copy the input
        std::vector<T> tmp(input);
        // sort the copy
        std::sort(tmp.begin(), tmp.end());
        return tmp;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
// Context is configured with a ConcreteStrategy object.
// maintains a reference to a Strategy object.
// may define an interface that lets Strategy access its data.
///////////////////////////////////////////////////////////////////////////////////////////
template <typename T> class Context {
  public:
    explicit Context(std::unique_ptr<SortStrategy<T>>&& strategy)
        : m_strategy(std::move(strategy)) {};
    ~Context() = default;

  public:
    /** @brief change the strategy in run-time */
    void setStrategy(std::unique_ptr<SortStrategy<T>>&& strategy) {
        m_strategy = std::move(strategy);
    }

    std::vector<T> executeStrategy(std::vector<T> const& input) {
        return m_strategy->sort(input);
    }

  private:
    std::unique_ptr<SortStrategy<T>> m_strategy; // encapsulate the desired strategy
};

#endif //__STRATEGY_HPP
