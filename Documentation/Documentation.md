# 24.3 9:30 Midterm meeting

# High level description
- Chosen structure: MVC (Model, View, Controller).

- Components:

    * Backend:
        - API handler (One or two?)
        - Main
        - Ilmatieteenlaitos Model
        - Ilmatieteenlaitos Controller
        - Findgrid Model
        - Findgrid Controller

    * Frontend:
        - Findgrid View
        - Ilmatieteenlaitos View
        - 

- Libraries:
    - Qt

- Technologies:
    - Postman
    - Qt
    - QML

## More detailed description

How data flows through the program:
Baseapihandler is inherited into fingrid- and fmihandlers which  
handle the api calls to Fingrid and Ilmatieteenlaitos respectively.  
Model consists of datahandler that gets the data from apihandlers and  
processes it ready for Chart. Chart processes data further ready to be  
shown in a graph. Main QML then gets the data from Chart and shows it in a graph.

Responsibilities:
Apihandlers need to call the API and to make sure that the get the data in a reply.
Datahandler and Chart need to handle the data and convert it to be ready for QML.
Main QML needs to show the data.

### Interfaces
As we're not completely sure on how the data should flow, we don't set all
interfaces in stone. This is due to not knowing the capabilities what our tech stack
has. For example, we're not completely sure whether it's possible to send data
from an API to a chart directly, instead of sending it through a parser and/or
long term storage, and we might have to come up with new interfaces to deal with
these problems.

As for now, we use mainly three interfaces for dataflow:

* BaseAPIhandler, a class to connect to the APIs. APIs connecting to the services
should derive from this class

* DataHandler class. This class is currently parsing XML, and sending data to the UI.

* Chart class. This is for showing the data gathered from the APIs.

Currently, the the program is used like this:

1) The user opens up the program, and presses "read data"
2) The program makes an fixed API call through the UI
3) This call goes to a datahandler, to the API. The resulting data flows from
API classes to the datahandler to the UI and finally the user sees the call.

### Interfaces/classes we expect in our final design

* Class for creating API calls

Now our program uses datahandler in a hacky way to send API requests.
An interface or a class dealing the requests from the user should be clearer.
This interface would connect to the view and signal requests to the API classes.

* Class to manipulate dates

As the API requests heavily depend on particular date formats, there is a need
to add some datetime string manipulation somewhere in the controller. This might
not need to be a class, but rather a set of functions.


There might be other interfaces we need to implement certain functionality
mentioned in the specification. Things like large-scale data collection
and statistical calculations based on the data might need interfaces of their own.
However, as we're not completely how such interfaces should or could behave,
we leave the design of them for a later stage.



## Self-evaluation (midterm)

Since the prototype phase, we have added a new,  
improved high-level description that doesn't necessarily change anything,  
but describes it better and clearer. When it comes to what is implemented  
so far, we have gone fully according to our better description. And we would  
imagine that our design is what the end result will look like, but maybe  
smaller additions will come in the future that we haven't thought about.
