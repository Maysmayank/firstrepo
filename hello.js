/*let num=78.0;
console.log(typeof num);
num=parseFloat(num);
console.log(typeof num);
// template string 
let age="22";
let name="joames";
let final=`My name is ${name} and age is ${+age}`;
console.log(final);
console.log(typeof age)

// unshift adds element to first index nd shift remove the element to the firt index
// push add element to last nd pop delete element from last
let array1=[1,2,3,4];
let array2=array1;
console.log("first array is" , array1);
console.log("second array is ", array2);
array1.push(888);
console.log("first array is" , array1);
console.log("second array is ", array2);

//cloning array means memeory will be assigned uniwuely in heap
let array1=[1,2,3,4];
let array2=[...array1];

console.log("first array is" , array1);
console.log("second array is ", array2);
array1.push(888);
console.log("first array is" , array1);
console.log("second array is ", array2);

let s=salfmsl;
console.log(s);
const newarr=[..."abcdef","123445"] // **************************this will printthe string in word by wword and also for the numbers 


//========'''''''' array destructuring to extratx elements from array neatly

const array=["res",23424,"erwe0","f"];
let [var1,var2,...temparr]=array;
console.log(var1,var2,temparr);



*/
// objects------------->

const person={ name:"Mayank" ,
               "person age":20 ,
               hobbies:["football","singing","hanging around"]
};

let hobbiesarray=[...person.hobbies];
//person.hobbies.push("Coding");
//console.log(person.hobbies);

//console.log(hobbiesarray);
person.gender="male";
//console.log(person.age)
//console.log(person["age"])

//console.log(person["person age"]); // we can;t access this string key using dot operator we need to use brackets its the differnce *********************
const keyfromuser_email="User E-mail";
person[`${keyfromuser_email}`]="mayank@gmail.com";  
// or 
person[keyfromuser_email]="mayank@gmail.com";  

person.fst="ffsfsdfsfsf";    // new key value pair cant be added using [] opererator********************

//console.log(person)

// traversing in objects
/*let i=0;
for (key in person){

    console.log( "object "+i ,key, " : ",person[key]);
    i++;
}


console.log(Object)
*/

// ------------////computed properties 
const obj={}  //we can also add the value to this emty object but by modifying hte below code do it on your own
//const key1="name";
//let key2 = "mail";
const value1="mayank";
let value2=null;
const Object={
 //   [key1] : value1,
   // [key2] : value2
} 

//Object[key1]=value1
//Object[key2]=value2

//console.log(Object);

// spread operator in objects case ******************************************IMPORTANT[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]

const newobject={...Object,..."3445",...{"key1":"valuee1"},...["gggg","fwfw"]};
//console.log(newobject)
//-----------objcet destrucutring
const bandobj={
    bandname: "One direction",
    song :"8888",
    leader:"harry styles",
    views:"30 Billion"
}

let { bandname , song }=bandobj;               //   bandname ='onedirection'     and        song = "mirror"
//console.log(bandname,"\nsong name is ", song);
// we can modify the bandname also by : bandname ="new name " only if const is not the variable used to declare duronig destructuring.

const {bandname:var1,song: var2,...restelements}=bandobj;
//console.log(var1,song)             // it will print the value 
//console.log(restelements);   // it will print rest of the elements 

//______objects in array---------------------useful in rweal world
const users=[{name:"def",class:"kent"},{name :"ramans", class:" nine"},{name:"yts"}];
//for (let user of users){

   // console.log(user.name);
//}

//let num=13;

//const armstrong=(number)=>{
//let temp=num;
    // let sum=0;
    // while(temp>0){
    //     let remain=temp%10;
    //     sum+=remain*remain*remain;
    //     temp=parseInt(temp/10);
    // }
    // if(sum==num){
    //     return "armstrong";
    // }
    // else{
    //     return"not an armstrong ";
    // }

    // }
    // console.log(armstrong(num));

//parameter destrcuting
const prompt=require("prompt-sync")({sigint:true});
//et keys1,keys2,val1,val2;
//const perso={




const takevalues=()=>{
       keys1=prompt("enter key1 : ");
     keys2=prompt("enter key2 : ")
      val1=prompt("enter value 1 : "); 
 val2=prompt("Enter value2 : ");
    perso[keys1]=val1;
    perso[keys2]=val2;
}

const showobjvals=({keys1,keys2})=>{
        console.log(keys1);
}

//takevalues();
//console.log(perso)
//showobjvals(perso)


//callback functions 

const myfunction=(name)=>{
    console.log("inside myfunction");
    console.log(`my name is ${name}`)

}
const callbackfunction=(callback)=>{
    console.log("inside callback function");
    callback("Mayank");
}

// callbackfunction(myfunction);
let arr1=[1,2,3,4];

for(let i=0;i<10;i++){
    arr1[i+1]={...arr1[i]};


}
//console.log(arr1);
//array methods 
//forEach(callback)
let numbers=[1,2,3,4,1000];
const multiplyby2=(number)=>{
    console.log(`${number} X 2 = ${number*2}`)

}
//numbers.forEach(multiplyby2);
//sum the array elements
let sum=0;
const sumelements=(number)=>{
    sum+=number;
    return sum;
}
let x=sumelements
//numbers.forEach(x)

//map function                 it has returntype if no return is passed it will print undefined iin array format [used to print elements in separate aray]
const sumarray=numbers.map(sumelements);
//console.log(sumarray);

// filter method/funtction
const iseven=(num)=>{
    return num%2===0;

}
const c=numbers.filter(iseven);
//console.log(c);
const num=[1,2,3,4];
//reduce method
sum=num.reduce((accumulator,currentvalue)=>{
    return accumulator+currentvalue;
});
//console.log(sum);
// accumulator     currentvalue     return
//    1                 2             3
//    3                 3               6
//    6                 4              10

const usercart=[
    {productid:1 ,productprice:1000},
    {productid:2 ,productprice:5000},
    {productid:3 ,productprice:7000},
    {productid:3 ,productprice:55000},
    {productid:3 ,productprice:10000},

]

function sumprice(totalprice,currentval){
    return totalprice + currentval.productprice;
}

const totalamt=usercart.reduce(sumprice,0);
//console.log(totalamt);

//sort    ---- this method will effect original array
const xnum=[1,45,2,5744,63,33,0];
// xnum.sort();       it will sort on the basis of ascii value,the elements in array treated as string
//console.log(xnum.sort((a,b)=>{return b-a}));

//const checkprice=(number)=>{
    //return number.productprice>5000;

//}
//const arr= usercart.some(checkprice);
//console.log(arr);


// set 
// it is iterable 
// dont have index based access
//order isnot guranteed
// unique items allowed
//const y=new Set([1,2,23,2,2,2,2,2,8])


//clone using obj.Assign (we can also use spread operator)
const objx={
    key1:"vals1",
    key2:"anof"
}
//let objx2={...objx};
//const objx2=Object.assign({},objx);
//objx.key3="ramson";
//console.log(objx);
//console.log(objx2);
if (typeof Object.create !== 'function') {
    Object.create = function (proto, propertiesObject) {
        if (typeof proto !== 'object' && typeof proto !== 'function') {
            throw new TypeError('Object prototype may only be an Object: ' + proto);
        }
        function F() {}
        F.prototype = proto;
        return new F();
    };
}


const usermethods={
    about : function(){
        return this.name,this.age;
    },
    sing: function(){
        return "dfef";
    }

}

const base_createuser=(name,age,number,message)=>{
    const user_proto=Object.create(usermethods);
    user_proto.name=name;
    user_proto.number=number;
    user_proto.age=age;
    user_proto.message=message;
    return base_createuser;
}

const user1=base_createuser("mayank",20,8187446602,"hi");
console.log(user1.about);