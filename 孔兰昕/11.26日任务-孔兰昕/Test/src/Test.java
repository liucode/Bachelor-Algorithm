import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;


public class Test{
	static Set<String> set = new TreeSet<String>();

	public static void main(String args[]) {

		String string = "eaa";
		new Test().combination(string.toCharArray(),
				string.toCharArray().length);
		Iterator<String> i = set.iterator();
		while (i.hasNext()) {
			System.out.println((String) i.next());
		}		
	}

	public void combination(char[] a, int len) {

		String s = new String(a);

		if (len == 2) {

			set.add(new String(a));			
			change(a, a.length - 2, a.length - 1);
			set.add(new String(a));
		} else {
			for (int i = a.length - len; i < a.length; i++) {
				a = s.toCharArray();

				char temp2 = a[a.length - len];
				a[a.length - len] = a[i];
				a[i] = temp2;

				char[] c = a;
				combination(c, len - 1);
			}
		}

	}

	public void change(char[] a, int s, int d) {

		char temp = a[s];
		a[s] = a[d];
		a[d] = temp;

	}

	
}

