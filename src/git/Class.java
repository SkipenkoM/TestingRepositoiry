package git;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;

public class Class{
	public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
    	String filename = "vehicles.dat";
    	ArrayList<Vehicle> vehicles = new ArrayList<Vehicle>();
    
    	int f = 3;

    	// Десереалізація
    	try(ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))){
    		vehicles=((ArrayList<Vehicle>)ois.readObject());
        }
        catch(Exception ex){ 
            System.out.println(ex.getMessage());
        }
    	
    	// Кілька попередньо заданих елементів списку
    	// Для зручності
    	// Після першого виходу с програми увесь наявний список 
    	// буде записано до vehicles.dat і потім зчитано при запуску

    	/*Car m1 = new Car(9, "nissan", "1991",  "green",451, 12, "sedan");
    	Car m2 = new Car(6, "volk", "1999", "green", 345, 14,"pickup");
    	Car m3 = new Car(8, "nissan", "1982", "green", 894, 8, "cope");
    	Track m4 = new Track(7, "RBM", "2004", "red", 468, 24, 6000);
    	Track m5 = new Track(10, "nissan", "1995", "green", 974, 53, 20000);
    	
    	vehicles.add(m1);
    	vehicles.add(m2);
    	vehicles.add(m3);
    	vehicles.add(m4);
    	vehicles.add(m5);*/
        boolean c=true;
        System.out.print("Welcome!\n");
        while (c) {
            System.out.print("\n 1.Create new Car \n 2.Create new Track \n 3.Delete via ID \n 4.Show List (all) \n 5.Show List (Сars) \n 6.Show List (Trucks) \n 7.Search via Car brand \n 8.Search via Body type \n 9.Search via Load capasity \n 0.Exit and Serialization\n");
            int k = in.nextInt();
            switch (k) {
            
                case 1:{
                	// Додавання Car
                	int new_id = 0;
                	int matches_unique_check = 0;
                	// Перевірка унікальності
                	boolean id_is_uniqe = false;
                	while( id_is_uniqe == false ) {
                        System.out.print("Input a ID (numbers only): ");
                        new_id = in.nextInt();	
                        for(int i=0; i<vehicles.size(); i++){
                        	int current_id = vehicles.get(i).getID();
                        	if(current_id==new_id) {
                        		System.out.println("ID already exist!");
                        		matches_unique_check++;
                        		break;
                    		}
                    		matches_unique_check = 0;
                    	}
                		if(matches_unique_check==0){
                			id_is_uniqe = true;
                		}
                	}
                   
                    // Введення данних
                	in.nextLine();
                    System.out.print("Input Car brand:");
                    String new_car_brand = in.nextLine();
                    
                    //in.nextLine();
                    System.out.print("Input Year of manufacture:");
                    String new_year_of_manufacture = in.nextLine();
                    
                    //in.nextLine();
                    System.out.print("Input Color:");
                    String new_color = in.nextLine();

                    System.out.print("Input Cost of car (numbers only): ");
                    int new_cost_of_car = in.nextInt();
                    
                    System.out.print("Input Fuel cost per 100 km (numbers only): ");
                    int new_fuel_cost_per_100_km= in.nextInt();
                    
                    in.nextLine();
                    System.out.print("Input Body type:");
                    String newbody_type = in.nextLine();
                    
                	Car car = new Car(new_id, new_car_brand, new_year_of_manufacture, new_color, new_cost_of_car, new_fuel_cost_per_100_km, newbody_type);
                	
                	vehicles.add(car);
                    break;
                }
                case 2:{
                	// Додавання Track
                	int new_id = 0;
                	int matches_unique_check = 0;
                	// Перевірка унікальності
                	boolean id_is_uniqe = false;
                	while( id_is_uniqe == false ) {
                        System.out.print("Input a ID (numbers only): ");
                        new_id = in.nextInt();	
                        for(int i=0; i<vehicles.size(); i++){
                        	int current_id = vehicles.get(i).getID();
                        	if(current_id==new_id) {
                        		System.out.println("ID already exist!");
                        		matches_unique_check++;
                        		break;
                        	}
                        	matches_unique_check = 0;
                        }
                        if(matches_unique_check==0){
                        	id_is_uniqe = true;
                        }
                	}
                	// Введення данних
                	in.nextLine();
                    System.out.print("Input Car brand:");
                    String new_car_brand = in.nextLine();
                    
                    System.out.print("Input Year of manufacture:");
                    String new_year_of_manufacture = in.nextLine();
                    
                    System.out.print("Input Color:");
                    String new_color = in.nextLine();

                    System.out.print("Input Cost of car (numbers only): ");
                    int new_cost_of_car = in.nextInt();
                    
                    System.out.print("Input Fuel cost per 100 km (numbers only): ");
                    int new_fuel_cost_per_100_km= in.nextInt();
                   
                    System.out.print("Input Load capacity (numbers only): ");
                    int newload_capacity = in.nextInt();
                    
                    Track truck = new Track(new_id, new_car_brand, new_year_of_manufacture, new_color, new_cost_of_car, new_fuel_cost_per_100_km, newload_capacity);

                	vehicles.add(truck);
                    break;
                }
                case 3:{
                	// Видалення за ID
                	System.out.print("Input a ID (numbers only): ");
                    int searched_id_to_delete = in.nextInt();
                    int matches_delete = 0;
                    for(int i=0; i<vehicles.size(); i++){
                    	int current_id = vehicles.get(i).getID();
                    	if(current_id==searched_id_to_delete) {
                    		vehicles.remove(i);
                    		matches_delete++;
                    	}
                    }
                    System.out.print("Objects removed: "+ matches_delete);
                    break;
                }    
                case 4:{
                	// Вивід на екран
                    for(int i=0; i<vehicles.size(); i++){
                    		vehicles.get(i).display();
                    }
                    break;
                }   
                case 5:{
                	// Вивід на екран
                    for(int i=0; i<vehicles.size(); i++){
                    	if(vehicles.get(i) instanceof Car ) {
                    		vehicles.get(i).display();
                    	}
                    }
                    break;
                }   
                case 6:{
                	// Вивід на екран
                    for(int i=0; i<vehicles.size(); i++){
                    	if(vehicles.get(i) instanceof Track ) {
                    		vehicles.get(i).display();
                    	}
                    }
                    break;
                }  
                case 7:{
                	// Пошук за Car brand
                    in.nextLine(); 
                    System.out.print("Input Body type:");
                    String searched_car_brand = in.nextLine();
                	//System.out.print("Input a Car brand (numbers only): ");
                    //int searched_id_to_find = in.nextInt();
                    int matches_find = 0;
                    for(int i=0; i<vehicles.size(); i++){
                    	String current_car_brand = vehicles.get(i).getCar_brand();
                    	if(current_car_brand.equals(searched_car_brand)) {
                    		vehicles.get(i).display();
                    		matches_find++;
                    	}
                    }
                    System.out.print("Matches found: "+ matches_find);
                    break;
                }    
                case 8:{
                	// Пошук за Body type
                    in.nextLine(); 
                    System.out.print("Input Body type:");
                    String searched_body_type = in.nextLine();
                    int matches = 0;
                    for(int i=0; i<vehicles.size(); i++){
                    	if(vehicles.get(i) instanceof Car ) {
                        	String current_body_type = ((Car) vehicles.get(i)).getBody_type();
                        	if(current_body_type.equals(searched_body_type)) {
                        		vehicles.get(i).display();
                        		matches++;
                        	}
                    	}
                    }
                    System.out.print("Matches found: "+ matches);
                    break;
                }   
                case 9:{
                	// Пошук за Load capasity
                	System.out.print("Input a Course(numbers only): ");
                    int searched_load_capasity = in.nextInt();
                    int matches = 0;
                    for(int i=0; i<vehicles.size(); i++){
                    	if(vehicles.get(i) instanceof Track ) {
                        	int current_load_capasity  = ((Track)vehicles.get(i)).getLoad_capacity();
                        	if(current_load_capasity== searched_load_capasity) {
                        		vehicles.get(i).display();
                        		matches++;
                        	}
                    	}
                    }
                    System.out.print("Matches found: "+ matches);
                    break;
                }    
                case 0:{
                	// Сереалізація та Вихід
                    try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))){
                        oos.writeObject(vehicles);
                        System.out.println("File has been written");
                    }
                    catch(Exception ex){
                        System.out.println(ex.getMessage());
                    } 
                    c=false;
                    break;
                 }   
                 default:{
                	 System.out.println("Unknown operration");
                	 break;
                 }	 
            }
        }
    }
}

class Vehicle implements Serializable {
      
    private int id;
    private String car_brand;
    private String year_of_manufacture;
    private String color;
    private int cost_of_car;
    private int fuel_cost_per_100_km;
    
    public int getID(){ return id; }
    public String getCar_brand(){ return car_brand; }
    public String getYear_of_manufacture(){ return year_of_manufacture; }
    public String getColor(){ return color; }
    public int getCost_of_car(){ return cost_of_car; }
    public int getFuel_cost_per_100_km(){ return fuel_cost_per_100_km; }
      
    public Vehicle(int id, String car_brand, String year_of_manufacture, String color, int cost_of_car, int fuel_cost_per_100_km){
        this.id=id;
        this.car_brand=car_brand;
        this.year_of_manufacture=year_of_manufacture;
        this.color=color;
        this.cost_of_car=cost_of_car;
        this.fuel_cost_per_100_km=fuel_cost_per_100_km;
    }
   
    public void display(){
        System.out.println("ID: " + id);
        System.out.println("Car brand: " + car_brand);
        System.out.println("Year of manufacture: " + year_of_manufacture);
        System.out.println("Color: " + color);
        System.out.println("Cost of car: " + cost_of_car);
        System.out.println("Fuel cost per 100 km: " + fuel_cost_per_100_km);
    }
}
class Car extends Vehicle{
  
    private String body_type;
    
    public String getBody_type(){ return body_type; }
    
      
    public Car(int id, String car_brand, String year_of_manufacture, String color, int cost_of_car, int fuel_cost_per_100_km, String body_type) {
        super(id, car_brand, year_of_manufacture, color, cost_of_car, fuel_cost_per_100_km);
        this.body_type=body_type;
    }
    @Override
    public void display(){
    	System.out.printf("Car \n");          
        System.out.println("ID: " + getID());
        System.out.println("Car brand: " +  getCar_brand());
        System.out.println("Year of manufacture: " + getYear_of_manufacture());
        System.out.println("Color: " + getColor());
        System.out.println("Cost of car: " + getCost_of_car());
        System.out.println("Fuel cost per 100 km: " + getFuel_cost_per_100_km());
        System.out.printf("Body type %s \n", body_type);
        System.out.printf(" \n");
    }
}

class Track extends Vehicle{
	  
    private int load_capacity;
    public int getLoad_capacity(){ return load_capacity; }
      
    public Track(int id, String car_brand, String year_of_manufacture, String color, int cost_of_car, int fuel_cost_per_100_km, int load_capacity) {
    	super(id, car_brand, year_of_manufacture, color, cost_of_car, fuel_cost_per_100_km);
        this.load_capacity=load_capacity;
    }
    @Override
    public void display(){
    	System.out.printf("Track \n");
        System.out.println("ID: " + getID());
        System.out.println("Car brand: " +  getCar_brand());
        System.out.println("Year of manufacture: " + getYear_of_manufacture());
        System.out.println("Color: " + getColor());
        System.out.println("Cost of car: " + getCost_of_car());
        System.out.println("Fuel cost per 100 km: " + getFuel_cost_per_100_km());
        System.out.printf("Load capacity: %d \n", load_capacity);
        System.out.printf(" \n");
    }
}