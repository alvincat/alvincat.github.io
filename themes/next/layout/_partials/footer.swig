<script async src="https://dn-lbstatics.qbox.me/busuanzi/2.3/busuanzi.pure.mini.js"></script>
<div style="color:red" class="copyright" >
  {% set current = date(Date.now(), "YYYY") %}
  &copy; {% if theme.since and theme.since != current %} {{ theme.since }} - {% endif %}
  <span  itemprop="copyrightYear">{{ current }}</span>
  <span class="with-love">
    <i class="fa fa-{{ theme.authoricon }}"></i>
  </span>
  <span class="author" itemprop="copyrightHolder">{{ config.author }}</span>
</div>

{% if theme.copyright %}

<!--
<div style="color:red" class="powered-by">
  {{ __('footer.powered', '<a class="theme-link" href="https://hexo.io">Hexo</a>') }}
</div>

<div style="color:red" class="theme-info">
  {{ __('footer.theme') }} -
  <a class="theme-link" href="https://github.com/iissnan/hexo-theme-next">
    NexT.{{ theme.scheme }}
  </a>
</div>
-->

<div style="color:red" class="powered-by">
  <i class="fa fa-user-md"></i><span id="busuanzi_container_site_uv">
    访客数:<span id="busuanzi_value_site_uv"></span>
  </span>
</div>


<div style="color:red" class="theme-info">
  <div class="powered-by"></div>
  <span class="post-count" >全站共{{ totalcount(site) }}字</span>
</div>

{% endif %}
