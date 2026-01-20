function SayHelloWorld(){
    try{
        try{
          throw {"name": "Vishesh", "age" : 18, "State" : "haryana"}
        }catch(err){
           throw err
        }
    }catch(err){
       console.log(`${err.name} ${err.age} ${err.State}`);
    }
}
SayHelloWorld();
