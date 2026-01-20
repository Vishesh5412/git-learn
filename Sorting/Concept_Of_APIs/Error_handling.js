function SayHelloWorld(){
    try{
        try{
          throw {"name": "Vishesh", "age" : 18, "State" : "haryana"} 
           // *** / this creates the error object and will be available to catch block 
           // Now the function is directly exited from there and directly moved to the catch part
           // ***
        }catch(err){
           throw err
        }
        finally{
            console.log('This is inside finally');
        }
    }catch(err){
       console.log(`${err.name} ${err.age} ${err.State}`);
       /*** Above is the case of nested try catch the inside try which contain try and catch throw an error ***
       / (Remember the error is passed to catch not due to inside try but by inside catch ***/
    }finally {
        console.log('This is outside finally');
    }
}
SayHelloWorld();


 //so there are only two ways through which the catch of a function can hit
 // *** ii) or by throwing an error ***

  // *** Point to be noted ***
 // *** Key behavior of finally

//  i) finally always runs immediately after the try block finishes, whether:

//  ii) The try completed normally, or

// iii)The try threw an error.

//  iv) Even if the catch block re-throws the error, the finally runs before the error leaves the current try-catch-finally. ***