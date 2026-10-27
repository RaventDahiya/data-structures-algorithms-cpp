class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class constructor {
    public static void main(String[] args) {
        Person person = new Person("John Doe");
        System.out.println("Name: " + person.getName());
    }
}