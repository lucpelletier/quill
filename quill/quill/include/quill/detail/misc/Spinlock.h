#pragma once

#include "quill/detail/misc/Attributes.h"
#include <atomic>
#include <mutex> // for std::lock_guard

namespace quill
{
namespace detail
{
/**
 * A Spinlock class
 */
class Spinlock
{
public:
  /**
   * Constructs a new spin lock.
   */
  Spinlock() = default;

  /**
   * Acquires the lock, spinning until successful.
   */
  void lock() noexcept;

  /**
   * Tries to acquire the lock, spinning until successful.
   * @return true if lock was acquired, false otherwise
   */
  QUILL_NODISCARD bool try_lock() noexcept;

  /**
   * Releases the lock.
   *
   * @note Behaviour is undefined if the lock is released from a different
   * thread to the one that acquired it.
   */
  void unlock() noexcept;

private:
  std::atomic_flag _Spinlock_flag = ATOMIC_FLAG_INIT;
};
} // namespace detail
} // namespace quill