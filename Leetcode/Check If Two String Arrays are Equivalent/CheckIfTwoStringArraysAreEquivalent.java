public static boolean checkEquality(String[] s1, String[] s2) {
    if (s1 == s2)
        return true;

    if (s1 == null || s2 == null)
        return false;

    int n = s1.length;
    if (n != s2.length)
        return false;

    for (int i = 0; i < n; i++) {
        if (!s1[i].equals(s2[i]))
            return false;
    }

    return true;
}