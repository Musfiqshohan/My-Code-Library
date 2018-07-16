BufferedReader reader = null;

try {
    File file = new File("sample-file.dat");
    reader = new BufferedReader(new FileReader(file));

    String line;
    while ((line = reader.readLine()) != null) {
        System.out.println(line);
    }

} catch (IOException e) {
    e.printStackTrace();
} finally {
    try {
        reader.close();
    } catch (IOException e) {
        e.printStackTrace();
    }
}
