// NOTE This is an implementation of Object Adapter where an object of the adaptee is aggregated in
// the Adapter class.
//
// NOTE There is another appraoch called Class Adapter where Adaptee and Target are inherited by the
// Adapter class. The Adaptee object is inherited privately but the Target object is inherited
// publicly. By doing so the Adaptee object can be seen by the Client as Target object.

#ifndef __ADAPTER_HPP__
#define __ADAPTER_HPP__

#include "pch.hpp"

namespace adapter {
///////////////////////////////////////////////////////////////////////////////////////////
// Adaptee Class
///////////////////////////////////////////////////////////////////////////////////////////
/** @brief The Adaptee contains some useful behavior, but its interface is incompatible
    with the existing client code. The Adaptee needs some adaptation before the
    client code can use it.
*/
class Adaptee {
  public:
    std::string SpecificRequest() const { return m_message; }

  private:
    std::string m_message =
        "This is a long text;Each sentence is seperated by a semicolon;This is not "
        "compatible with the client interface;Each line must ends with a dot and a new line "
        "char;";
};

///////////////////////////////////////////////////////////////////////////////////////////
// Target and Adapter Classes
///////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief The Target defines the domain-specific interface used by the client code.
 */
class Target {
  public:
    Target() = default;
    virtual ~Target() = default;
    Target(Target const& other) = delete;
    Target(Target&& other) = delete;
    Target& operator=(Target const& other) = delete;
    Target& operator=(Target&& other) = delete;

  public:
    virtual std::string Request() const {
        return "Target: The default target's behavior is compatible with the client interface.";
    }
};

/**
 * @brief The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
  public:
    Adapter(std::unique_ptr<Adaptee> adaptee) // NOTE: Adapter aggregates the adaptee
        : m_adaptee(std::move(adaptee)) {}

    // perform the adaption process
    std::string Request() const override {
        // get the adaptee's content
        std::string to_adapt = this->m_adaptee->SpecificRequest();
        // adapt this content
        auto pos = to_adapt.find(';');
        while (pos != to_adapt.npos) {
            to_adapt.erase(pos, 1);
            to_adapt.insert(pos, ".\n");
            pos = to_adapt.find(';');
        }
        return "Adapter: (TRANSLATED)\n" + to_adapt;
    }

  private:
    std::unique_ptr<Adaptee> m_adaptee;
};

///////////////////////////////////////////////////////////////////////////////////////////
// Client aggregates the Target object
///////////////////////////////////////////////////////////////////////////////////////////
/** @brief The client code supports all classes that follow the Target interface.
 */
class Client {
  public:
    Client(std::unique_ptr<Target> target)
        : m_target{std::move(target)} {}

    void request() const {
        std::cout << "\n\n**********************************************\n"
                     "The dispay on the client side shows the message comming from the target:\n"
                     "**********************************************\n"
                  << m_target->Request();
    }

  private:
    std::unique_ptr<Target> m_target;
};

} // end of namespace adapter

#endif // __ADAPTER_HPP__