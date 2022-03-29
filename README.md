# CosmosEngine
This is an engine based on TheCherno's Youtube Tutorials for creating an engine in C++

## Getting started
Visual studio 2019 is recommended for building the project. It is currently untested on any other environment.
To clone the repository, use `git clone --recursive https://github.com/thegritsch/CosmosEngine`

### Setting up the project structure
After downloading the project, run the [GenerateProjects.bat](https://github.com/thegritsch/CosmosEngine/blob/main/GenerateProjects.bat) file to generate the projects for visual studio.

### Building
Open the Solution in VS2019 and build it. Note that the first build might fail, because a folder that is not yet created is missing. In that case just build again and it should work flawlessly.


## Engine overview
The engine is implemented as a dynamic link library that itself links statically to submodules. 

### Using the engine
To use the engine, simply link the library to your application (this is already done with a sample app in the engine solution, called antares).
Then include the `<Cosmos.h>` header and let your application class inherit from `Cosmos::Application`.

### Interesting code parts
#### Macros for setting class type

`#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }`
                
This is a handy trick that utilizes the preprocessor and Templates to implement type determination without reliyng on reflection. The type argument is a class enum of all the different event types. The ##type command simply instructs the preprocessor to concatenate the argument to the string, eg. `EventType::WindowClose`.

#### Event dispatching
The engine uses a Template class event dispatcher to implement the eventing system.
```C++
template<typename T>
  bool Dispatch(EventFn<T> func)
  {
    if (m_Event.GetEventType() == T::GetStaticType())
    {
      m_Event.m_Handled = func(*(T*)&m_Event);
      return true;
    }
    return false;
  }
```
The code above creates an event dispatcher for every event type used. 
