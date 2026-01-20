 // *** Suppose an API ***


 export default async function signIn(req, res) {
    await connectToDatabase();
    if (req.method === "POST") {
      try {
        res.status(200).json({ message: "Logged in successfully", user });
      } catch (err) {
        console.error("SIGNIN ERROR", err);
        res.status(500).json({ message: "Internal server error" });
      }
    } else {
      res.setHeader("Allow", ["POST"]);
      res.status(405).end(`Method ${req.method} Not Allowed`);
    }
  }

  //suppose an calling function
  SignIn: async (userData) => {
    try {
      const res = await fetch("Some end point of APIs", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ /*Anything for post request */ }),
      });
      const data = await res.json();
      if (!res.ok) {
        console.log("Invalid credentials");
        if (res.status === 403 || res.status === 401 || res.status === 500) {
          toast.error(data.message);
        }
        throw { status: res.status, message: data.message || "Unknown error" };
      }
      console.log("Sign in successful");
      set({ authUser: data.user });
      await Router.push(ROUTES.HOMEPAGE);
      return data;
    } catch (error) {
      throw error;
    } finally {
      set({ is_auth_request_pending: false });
    }
  }

  //throw error resusable example
  try{
    SignIn( /*Inputs*/ );
  }catch(err){

  }


   // *** Inside this API the catch will block will only hit if there is any syntax error/wrong export etc ***
   // *** Generally developers don't write anything after res.status inside the try block as the response has alreay been sent ***
   // *** Any syntax error/ wrong export(IN API) will go in  catch which will send 500 status code which then can be seen by function***
   // *** IN calling function if any 4XX or 5XX status code is send it does not directly go into catch block until error is thrown
   // *** here it can be seen that in catch also the error is thrown to make it reusable in another function where this function is used